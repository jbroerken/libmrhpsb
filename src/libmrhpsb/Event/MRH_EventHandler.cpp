/**
 *  MRH_EventHandler.cpp
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
#include <cstring>
#include <new>

// External

// Project
#include "./MRH_EventHandler.h"
#include "../../../include/libmrhpsb/libmrhpsb/MRH_EventStorage.h"
#include "../../../include/libmrhpsb/libmrhpsb/MRH_PSBLogger.h"


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

#ifdef __MRH_MRHCKM_SUPPORTED__
MRH_EventHandler::MRH_EventHandler(const char* p_InputPath,
                                   const char* p_InputKey,
                                   const char* p_OutputPath,
                                   const char* p_OutputKey,
                                   const char* p_EventLimit,
                                   const char* p_TimeoutMS) : p_InputEventQueue(NULL),
                                                              p_OutputEventQueue(NULL)
{
    if (p_InputPath == NULL || std::strlen(p_InputPath) == 0 ||
        p_InputKey == NULL || std::strlen(p_InputKey) == 0 ||
        p_OutputPath == NULL || std::strlen(p_OutputPath) == 0 ||
        p_OutputKey == NULL || std::strlen(p_OutputKey) == 0 ||
        p_EventLimit == NULL || std::strlen(p_EventLimit) == 0 ||
        p_TimeoutMS == NULL || std::strlen(p_TimeoutMS) == 0)
    {
        throw MRH_PSBException("Invalid device info recieved!");
    }
    
    // Get param info
    try
    {
        s32_QueueTimeoutMS = std::stoi(p_TimeoutMS);
        
        if ((us_ReserveStep = std::stoi(p_EventLimit)) == 0)
        {
            us_ReserveStep = 1;
        }
        
        p_InputEventQueue = MRH_OpenInputQueueMRHCKM(p_InputPath, std::stoi(p_InputKey), std::stoi(p_EventLimit));
        p_OutputEventQueue = MRH_OpenOutputQueueMRHCKM(p_OutputPath, std::stoi(p_OutputKey), std::stoi(p_EventLimit));
    }
    catch (std::exception& e)
    {
        throw MRH_PSBException(std::string("Failed to open event queues: ") + e.what());
    }
    
    // Result
    if (p_InputEventQueue == NULL || p_OutputEventQueue == NULL)
    {
        Exit();
        
        if (MRH_GetEventQueueError() != MRH_EV_Error_Type::MRH_EV_ERROR_NONE)
        {
            throw MRH_PSBException(std::string("libmrhev error while initializing: ") + std::string(MRH_GetEventQueueErrorString()) + "!");
        }
        else
        {
            throw MRH_PSBException("Unknown libmrhev error while initializing!");
        }
    }
}
#endif

MRH_EventHandler::MRH_EventHandler(const char* p_InputFD,
                                   const char* p_OutputFD,
                                   const char* p_EventLimit,
                                   const char* p_TimeoutMS) : p_InputEventQueue(NULL),
                                                              p_OutputEventQueue(NULL)
{
    if (p_InputFD == NULL || std::strlen(p_InputFD) == 0 ||
        p_OutputFD == NULL || std::strlen(p_OutputFD) == 0 ||
        p_EventLimit == NULL || std::strlen(p_EventLimit) == 0 ||
        p_TimeoutMS == NULL || std::strlen(p_TimeoutMS) == 0)
    {
        throw MRH_PSBException("Invalid file descriptors recieved!");
    }
    
    // Get param info
    try
    {
        s32_QueueTimeoutMS = std::stoi(p_TimeoutMS);
        
        if ((us_ReserveStep = std::stoi(p_EventLimit)) == 0)
        {
            us_ReserveStep = 1;
        }
        
        p_InputEventQueue = MRH_OpenInputQueuePipe(std::stoi(p_InputFD), std::stoi(p_EventLimit));
        p_OutputEventQueue = MRH_OpenOutputQueuePipe(std::stoi(p_OutputFD), std::stoi(p_EventLimit));
    }
    catch (std::exception& e)
    {
        throw MRH_PSBException(std::string("Failed to open event queues: ") + e.what());
    }
    
    // Result
    if (p_InputEventQueue == NULL || p_OutputEventQueue == NULL)
    {
        CheckLibraryError();
        Exit();
        
        throw MRH_PSBException(std::string("libmrhev event queue(s) failed to initialize!"));
    }
}

MRH_EventHandler::~MRH_EventHandler() noexcept
{
    Exit();
}

//*************************************************************************************
// Send
//*************************************************************************************

void MRH_EventHandler::SendEvents() noexcept
{
    // Check
    if (p_OutputEventQueue == NULL || (MRH_EventStorage::Singleton().GetCount() == 0 && MRH_CanSendEvents(p_OutputEventQueue) < 0))
    {
        return;
    }
    
    // Add as many events to queue as possible
    // NOTE: No limit, platform component and libmrhs protection
    MRH_EventStorage& s_EventStorage = MRH_EventStorage::Singleton();
    MRH_Event* p_Event;
    
    while ((p_Event = s_EventStorage.GetEvent()) != NULL)
    {
        if (MRH_AddEvent(p_OutputEventQueue, &p_Event) != NULL)
        {
            break;
        }
        
        s_EventStorage.RemoveFront();
    }
    
    CheckLibraryError();
    
    // Send events
    if (MRH_CanSendEvents(p_OutputEventQueue) == 0)
    {
        MRH_SendEvents(p_OutputEventQueue);
        CheckLibraryError();
    }
}

//*************************************************************************************
// Recieve
//*************************************************************************************

std::vector<MRH_Event*>& MRH_EventHandler::RecieveEvents() noexcept
{
    // Check
    if (p_InputEventQueue == NULL)
    {
        return v_Recieved;
    }
    
    // Recieve events
    if (MRH_RecieveEvents(p_InputEventQueue, s32_QueueTimeoutMS) > 0)
    {
        MRH_Event* p_Event;
        
        while ((p_Event = MRH_GetEvent(p_InputEventQueue)) != NULL)
        {
            if (v_Recieved.size() == v_Recieved.capacity())
            {
                v_Recieved.reserve(v_Recieved.capacity() + us_ReserveStep);
            }
            
            v_Recieved.emplace_back(p_Event);
        }
    }
    
    // NULL because of no remaining event produces no error
    CheckLibraryError();
    
    return v_Recieved;
}

//*************************************************************************************
// Exit
//*************************************************************************************

void MRH_EventHandler::Exit() noexcept
{
    // Remove queues
    p_InputEventQueue = MRH_CloseEventQueue(p_InputEventQueue);
    p_OutputEventQueue = MRH_CloseEventQueue(p_OutputEventQueue);
    
    CheckLibraryError();
    
    // NOTE: EventStorage cleans itself!
    for (auto& Event : v_Recieved)
    {
        if (Event->p_Data != NULL)
        {
            free(Event->p_Data);
        }
        
        free(Event);
    }
    
    v_Recieved.clear();
}

//*************************************************************************************
// Error
//*************************************************************************************

void MRH_EventHandler::CheckLibraryError() noexcept
{
    if (MRH_GetEventQueueError() != MRH_EV_Error_Type::MRH_EV_ERROR_NONE)
    {
        MRH_PSBLogger::Singleton().Log(MRH_PSBLogger::WARNING, "libmrhev error while processing events: " +
                                                               std::string(MRH_GetEventQueueErrorString()) +
                                                               " (" +
                                                               std::string(MRH_GetEventQueueErrorFile()) +
                                                               ": " +
                                                               std::to_string(MRH_GetEventQueueErrorFileLine()) +
                                                               ")!",
                           "EventHandler.cpp", __LINE__);
        MRH_ResetEventQueueError();
    }
}

//*************************************************************************************
// Getters
//*************************************************************************************

bool MRH_EventHandler::GetRemainingEvents() const noexcept
{
    return MRH_CanSendEvents(p_OutputEventQueue) < 0 ? false : true;
}
