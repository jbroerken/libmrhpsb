/**
 *  MRH_EventStorage.h
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

#ifndef MRH_EventStorage_h
#define MRH_EventStorage_h

// C / C++
#include <mutex>
#include <vector>

// External
#include <MRH_Event.h>

// Project
#include "./MRH_PSBException.h"


class MRH_EventStorage
{
public:

    //*************************************************************************************
    // Singleton
    //*************************************************************************************

    /**
     *  Get the class instance. This function is thread safe.
     *
     *  \return The class instance.
     */

    static MRH_EventStorage& Singleton() noexcept;

    //*************************************************************************************
    // Clear
    //*************************************************************************************
    
    /**
     *  Clear all currently stored events. This function is thread safe.
     */
    
    void Clear() noexcept;
    
    //*************************************************************************************
    // Add
    //*************************************************************************************
    
    /**
     *  Add a event to storage. This function is thread safe.
     *
     *  \param p_Event The event to add.
     */
    
    void Add(MRH_Event* p_Event);
    
    //*************************************************************************************
    // Remove
    //*************************************************************************************
    
    /**
     *  Remove the first event in the container. The event will not be deleted.
     *  This function is thread safe.
     */
    
    void RemoveFront() noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************
    
    /**
     *  Get the amount of stored events. This function is thread safe.
     *
     *  \return The amount of stored events.
     */
    
    size_t GetCount() noexcept;
    
    /**
     *  Get the first (oldest) event in storage. This function is thread safe.
     *
     *  \return The oldest stored event.
     */
    
    MRH_Event* GetEvent() noexcept;
    
private:

    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************
    
    /**
     *  Default constructor.
     */
    
    MRH_EventStorage() noexcept;
    
    /**
     *  Default destructor.
     */
    
    ~MRH_EventStorage() noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    std::mutex c_Mutex;
    std::vector<MRH_Event*> v_Event;
    
protected:
    
};

#endif /* MRH_EventStorage_h */
