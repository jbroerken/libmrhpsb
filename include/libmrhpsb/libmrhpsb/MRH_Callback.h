/**
 *  MRH_Callback.h
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

#ifndef MRH_Callback_h
#define MRH_Callback_h

// C / C++

// External
#include <libmrhevdata.h>

// Project
#include "./MRH_EventStorage.h"


class MRH_Callback
{
public:

    //*************************************************************************************
    // Destructor
    //*************************************************************************************

    /**
     *  Default destructor.
     */

    virtual ~MRH_Callback() noexcept
    {}
    
    //*************************************************************************************
    // Callback
    //*************************************************************************************
    
    /**
     *  Perform a callback with a recieved user event.
     *
     *  \param p_Event The recieved user event.
     *  \param u32_GroupID The event group id for the user event.
     */
    
    virtual void Callback(const MRH_Event* p_Event, MRH_Uint32 u32_GroupID) noexcept
    {}
    
private:

    //*************************************************************************************
    // Data
    //*************************************************************************************
    
protected:

    //*************************************************************************************
    // Constructor
    //*************************************************************************************

    /**
     *  Default constructor.
     */

    MRH_Callback() noexcept
    {}
};

#endif /* MRH_Callback_h */
