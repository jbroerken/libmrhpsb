/**
 *  MRH_EventHandler.h
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

#ifndef MRH_EventHandler_h
#define MRH_EventHandler_h

// C / C++
#include <vector>

// External
#include <libmrhev.h>

// Project
#include "../../../include/libmrhpsb/libmrhpsb/MRH_PSBException.h"


class MRH_EventHandler
{
public:

    //*************************************************************************************
    // Constructor / Destructor
    //*************************************************************************************

#ifdef __MRH_MRHCKM_SUPPORTED__
    /**
     *  MRHCKM-based constructor.
     *
     *  \param p_InputPath The full path to the input device file.
     *  \param p_InputKey The input key.
     *  \param p_OutputPath The full path to the output device file.
     *  \param p_OutputKey The output key.
     *  \param p_EventLimit The max amount of event to be sent / recieved in a update.
     *  \param p_TimeoutMS The read timeout in milliseconds.
     */
    
    MRH_EventHandler(const char* p_InputPath,
                     const char* p_InputKey,
                     const char* p_OutputPath,
                     const char* p_OutputKey,
                     const char* p_EventLimit,
                     const char* p_TimeoutMS);
#endif
    
    /**
     *  Pipe-based constructor.
     *
     *  \param p_InputFD The event queue input file descriptor.
     *  \param p_OutputFD The event queue output file descriptor.
     *  \param p_EventLimit The max amount of event to be sent / recieved in a update.
     *  \param p_TimeoutMS The read timeout in milliseconds.
     */

    MRH_EventHandler(const char* p_InputFD,
                     const char* p_OutputFD,
                     const char* p_EventLimit,
                     const char* p_TimeoutMS);

    /**
     *  Copy constructor. Disabled for this class.
     *
     *  \param c_EventHandler EventHandler class source.
     */

    MRH_EventHandler(MRH_EventHandler const& c_EventHandler) = delete;

    /**
     *  Default destructor.
     */

    ~MRH_EventHandler() noexcept;

    //*************************************************************************************
    // Send
    //*************************************************************************************

    /**
     *  Send stored events.
     */
    
    void SendEvents() noexcept;
    
    //*************************************************************************************
    // Recieve
    //*************************************************************************************

    /**
     *  Recieve events.
     *
     *  \return The vector containing all recieved events.
     */

    std::vector<MRH_Event*>& RecieveEvents() noexcept;
    
    //*************************************************************************************
    // Exit
    //*************************************************************************************
    
    /**
     *  Exit the event queue.
     */
    
    void Exit() noexcept;
    
    //*************************************************************************************
    // Getters
    //*************************************************************************************

    /**
     *  Get wether events remain to send or not.
     *
     *  \return true if events remain, false if not.
     */
    
    bool GetRemainingEvents() const noexcept;
    
private:
    
    //*************************************************************************************
    // Error
    //*************************************************************************************
    
    /**
     *  Check libmrhev for errors.
     */
    
    inline void CheckLibraryError() noexcept;
    
    //*************************************************************************************
    // Data
    //*************************************************************************************

    // Event queue
    MRH_InputEventQueue* p_InputEventQueue;
    MRH_OutputEventQueue* p_OutputEventQueue;
    MRH_Sint32 s32_QueueTimeoutMS;

    // Event storage
    std::vector<MRH_Event*> v_Recieved;
    size_t us_ReserveStep; // Grow v_Recieved
    
protected:

};

#endif /* MRH_EventHandler_h */
