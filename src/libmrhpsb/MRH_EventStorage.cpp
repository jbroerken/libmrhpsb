/**
 *  MRH_EventStorage.cpp
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

// External

// Project
#include "../../include/libmrhpsb/libmrhpsb/MRH_EventStorage.h"
#include "../../include/libmrhpsb/libmrhpsb/MRH_PSBLogger.h"

// Pre-defined
#ifndef MRH_EVENT_STORAGE_RESERVE_STEP
    #define MRH_EVENT_STORAGE_RESERVE_STEP 100
#endif


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_EventStorage::MRH_EventStorage() noexcept
{}

MRH_EventStorage::~MRH_EventStorage() noexcept
{}

//*************************************************************************************
// Singleton
//*************************************************************************************

MRH_EventStorage& MRH_EventStorage::Singleton() noexcept
{
    static MRH_EventStorage c_EventStorage;
    return c_EventStorage;
}

//*************************************************************************************
// Clear
//*************************************************************************************

void MRH_EventStorage::Clear() noexcept
{
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    
    for (auto& Event : v_Event)
    {
        if (Event->p_Data != NULL)
        {
            free(Event->p_Data);
        }
        
        free(Event);
    }
    
    v_Event.clear();
}

//*************************************************************************************
// Add
//*************************************************************************************

void MRH_EventStorage::Add(MRH_Event* p_Event)
{
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    
    try
    {
        if (v_Event.size() == v_Event.capacity())
        {
            v_Event.reserve(v_Event.capacity() + MRH_EVENT_STORAGE_RESERVE_STEP);
        }
        
        v_Event.emplace_back(p_Event);
    }
    catch (std::exception& e)
    {
        throw MRH_PSBException(e.what());
    }
}

//*************************************************************************************
// Remove
//*************************************************************************************

void MRH_EventStorage::RemoveFront() noexcept
{
    if (v_Event.size() == 0)
    {
        return;
    }
    
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    v_Event.erase(v_Event.begin());
}

//*************************************************************************************
// Getters
//*************************************************************************************

size_t MRH_EventStorage::GetCount() noexcept
{
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    return v_Event.size();
}

MRH_Event* MRH_EventStorage::GetEvent() noexcept
{
    std::lock_guard<std::mutex> c_Guard(c_Mutex);
    return (v_Event.size() > 0 ? v_Event[0] : NULL);
}
