/**
 *  MRH_ThreadPool.h
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

#ifndef MRH_ThreadPool_h
#define MRH_ThreadPool_h

// C / C++
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <list>
#include <utility>
#include <memory>

// External

// Project
#include "../../../include/libmrhpsb/libmrhpsb/MRH_Callback.h"
#include "../../../include/libmrhpsb/libmrhpsb/MRH_PSBException.h"


class MRH_ThreadPool
{
public:

    //*************************************************************************************
    // Destructor
    //*************************************************************************************

    /**
     *  Default constructor.
     *
     *  \param us_ThreadCount The number of worker threads to use.
     */
    
    MRH_ThreadPool(size_t us_ThreadCount);
    
    /**
     *  Copy constructor. Disabled for this class.
     *
     *  \param c_ThreadPool ThreadPool class source.
     */

    MRH_ThreadPool(MRH_ThreadPool const& c_ThreadPool) = delete;
    
    /**
     *  Default destructor.
     */

    ~MRH_ThreadPool() noexcept;
    
    //*************************************************************************************
    // Add
    //*************************************************************************************
    
    /**
     *  Add a callback.
     *
     *  \param p_Callback The callback to add.
     *  \param u32_Type The event type for this callback,
     */
    
    void AddCallback(std::shared_ptr<MRH_Callback>& p_Callback, MRH_Uint32 u32_Type);
    
    /**
     *  Add a event as a job. This function is thread safe.
     *
     *  \param p_Event The recieved user event.
     *  \param u32_GroupID The event group id for the user event.
     */
    
    void AddJob(MRH_Event* p_Event, MRH_Uint32 u32_GroupID);
    
private:
    
    //*************************************************************************************
    // Types
    //*************************************************************************************
    
    typedef std::list<std::shared_ptr<MRH_Callback>> CallbackList;
    typedef std::unordered_map<MRH_Uint32, CallbackList> CallbackMap;
    typedef std::list<std::pair<MRH_Uint32, MRH_Event*>> JobList;
    
    //*************************************************************************************
    // Update
    //*************************************************************************************

    /**
     *  Update the thread pool.
     *
     *  \param p_Instance The thread pool instance to update with.
     */
    
    static void Update(MRH_ThreadPool* p_Instance) noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    // Thread
    std::list<std::thread> l_Thread;
    std::atomic<bool> b_Update;
    std::mutex c_ConditionMutex;
    std::mutex c_JobMutex;
    std::condition_variable c_Condition;
    
    // Callback
    CallbackMap m_Callback;
    
    // Job
    JobList l_Job;
    
protected:

};

#endif /* MRH_ThreadPool_h */
