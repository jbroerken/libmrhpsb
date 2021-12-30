/**
 *  MRH_ThreadPool.cpp
 *
 *  This file is part of the MRH project.
 *  See the AUTHORS file for Copyright information.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

// C / C++
#include <string>

// External

// Project
#include "./MRH_ThreadPool.h"
#include "../../../include/libmrhpsb/libmrhpsb/MRH_PSBLogger.h"

// Pre-defined
#ifndef MRH_PLATFORM_SERVICE_LOG_EVENTS
    #define MRH_PLATFORM_SERVICE_LOG_EVENTS 0
#endif


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_ThreadPool::MRH_ThreadPool(size_t us_ThreadCount) : b_Update(true)
{
    if (us_ThreadCount == 0)
    {
        throw MRH_PSBException("Invalid thread count for thread pool!");
    }
    
    try
    {
        while (us_ThreadCount > 0)
        {
            l_Thread.emplace_back(Update, this);
            --us_ThreadCount;
        }
    }
    catch (std::exception& e)
    {
        throw MRH_PSBException(e.what());
    }
}

MRH_ThreadPool::~MRH_ThreadPool() noexcept
{
    b_Update = false;
    c_Condition.notify_all();
    
    for (auto& Thread : l_Thread)
    {
        Thread.join();
    }
}

//*************************************************************************************
// Add
//*************************************************************************************

void MRH_ThreadPool::AddCallback(std::shared_ptr<MRH_Callback>& p_Callback, MRH_Uint32 u32_Type)
{
    auto It = m_Callback.find(u32_Type);
    
    // Add new if no callbacks for the type
    if (It == m_Callback.end())
    {
        if (m_Callback.insert(std::make_pair(u32_Type, CallbackList())).second == false)
        {
            throw MRH_PSBException("Failed to add callback for type " + std::to_string(u32_Type) + "!");
        }
        
        It = m_Callback.find(u32_Type);
    }
    
    // Add callback to type
    try
    {
        It->second.emplace_back(p_Callback);
    }
    catch (std::exception& e)
    {
        throw MRH_PSBException(e.what());
    }
}

void MRH_ThreadPool::AddJob(MRH_EVBase*& p_Event, MRH_Uint32 u32_GroupID)
{
    try
    {
        c_JobMutex.lock();
        l_Job.emplace_back(std::make_pair(u32_GroupID, p_Event));
        c_JobMutex.unlock();
        
        p_Event = NULL;
        
        c_Condition.notify_one();
    }
    catch (std::exception& e)
    {
        throw MRH_PSBException(e.what());
    }
}

//*************************************************************************************
// Update
//*************************************************************************************

void MRH_ThreadPool::Update(MRH_ThreadPool* p_Instance) noexcept
{
    MRH_PSBLogger& c_Logger = MRH_PSBLogger::Singleton();
    CallbackMap& m_Callback = p_Instance->m_Callback;
    JobList& l_Job = p_Instance->l_Job;
    
    MRH_EVBase* p_Event;
    MRH_Uint32 u32_GroupID;
    
    while (p_Instance->b_Update == true)
    {
        // Check for available jobs
        p_Instance->c_JobMutex.lock();
        
        if (l_Job.size() == 0)
        {
            p_Instance->c_JobMutex.unlock();
            
            std::unique_lock<std::mutex> c_UniqueLock(p_Instance->c_ConditionMutex);
            p_Instance->c_Condition.wait(c_UniqueLock);
        
            continue;
        }
        else
        {
            u32_GroupID = l_Job.begin()->first;
            p_Event = l_Job.begin()->second;
            l_Job.pop_front();
            
            p_Instance->c_JobMutex.unlock();
        }
        
        // Job available! Is there a callback for it?
        auto CBList = m_Callback.find(p_Event->GetType());
        
        if (CBList == m_Callback.end() || CBList->second.size() == 0)
        {
            c_Logger.Log(MRH_PSBLogger::WARNING, "No callback for event [ " +
                                                 std::to_string(p_Event->GetType()) +
                                                 " ]!",
                         "ThreadPool.h", __LINE__);
            delete p_Event;
            continue;
        }
        
        // Perform job on matching callbacks
        for (auto& Callback : CBList->second)
        {
#if MRH_PLATFORM_SERVICE_LOG_EVENTS > 0
            c_Logger.Log(MRH_PSBLogger::INFO, "Performing callback for event [ " +
                                              std::to_string(p_Event->GetType()) +
                                              " ] ...",
                         "ThreadPool.h", __LINE__);
#endif
            Callback->Callback(p_Event, u32_GroupID);
        }
        
        // Event used on all callbacks, clean up
        delete p_Event;
    }
}
