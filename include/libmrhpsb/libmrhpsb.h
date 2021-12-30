/**
 *  libmrhpsb.h
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

#ifndef libmrhpsb_h
#define libmrhpsb_h

// C / C++
#include <memory>

// External

// Project
#include "./libmrhpsb/MRH_Callback.h"
#include "./libmrhpsb/MRH_PSBException.h"
#include "./libmrhpsb/MRH_PSBLogger.h"
#include "./libmrhpsb/MRH_PSBRevision.h"


class MRH_EventHandler;
class MRH_ThreadPool;


class libmrhpsb
{
public:
    
    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************

    /**
     *  Default constructor.
     *
     *  \param s_Identifier The service identification string.
     *  \param argc Launch argument count.
     *  \param argv Launch arguments.
     *  \param us_ThreadCount The number of worker threads to use.
     */

    libmrhpsb(std::string const& s_Identifier,
              int argc,
              const char* argv[],
              size_t us_ThreadCount = 1);
    
    /**
     *  Default destructor.
     */
    
    ~libmrhpsb() noexcept;

    //*************************************************************************************
    // Update
    //*************************************************************************************

    /**
     *  Update platform service base.
     */
    
    void Update() noexcept;
    
    //*************************************************************************************
    // Add
    //*************************************************************************************
    
    /**
     *  Add a callback to the platform service base.
     *
     *  \param p_Callback The callback to add.
     *  \param u32_Type The event type for this callback.
     */
    
    void AddCallback(std::shared_ptr<MRH_Callback>& p_Callback, MRH_Uint32 u32_Type);
    
private:

    //*************************************************************************************
    // Getters
    //*************************************************************************************

    /**
     *  Check if an event type is valid for a callback. This function is thread safe.
     *
     *  \param u32_Type The event type to check.
     *
     *  \return true if valid, false if not.
     */
    
    bool IsValidEventType(MRH_Uint32 u32_Type) noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************
    
    MRH_EventHandler* p_EventHandler;
    MRH_ThreadPool* p_ThreadPool;
    
protected:
    
};

#endif /* libmrhpsb_h */
