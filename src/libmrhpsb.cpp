/**
 *  libmrhpsb.cpp
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
#include <csignal>

// External

// Project
#include "../include/libmrhpsb/libmrhpsb.h"
#include "./libmrhpsb/Event/MRH_EventHandler.h"
#include "./libmrhpsb/ThreadPool/MRH_ThreadPool.h"


//*************************************************************************************
// Data
//*************************************************************************************

namespace
{
    // Launch parameters
    typedef enum
    {
#ifdef __MRH_MRHCKM_SUPPORTED__
        MRH_PARAM_BIN = 0,
        MRH_PARAM_EV_INPUT_FD = 1,
        MRH_PARAM_EV_INPUT_KEY = 2,
        MRH_PARAM_EV_OUTPUT_FD = 3,
        MRH_PARAM_EV_OUTPUT_KEY = 4,
        MRH_PARAM_EV_EVENT_LIMIT = 5,
        MRH_PARAM_EV_TIMEOUT_MS = 6,

        MRH_PARAM_MAX = 6,

        MRH_PARAM_COUNT = 7
#else
        MRH_PARAM_BIN = 0,
        MRH_PARAM_EV_INPUT_FD = 1,
        MRH_PARAM_EV_OUTPUT_FD = 2,
        MRH_PARAM_EV_EVENT_LIMIT = 3,
        MRH_PARAM_EV_TIMEOUT_MS = 4,

        MRH_PARAM_MAX = 4,

        MRH_PARAM_COUNT = 5
#endif
    }MRH_Parameters;

    // Last signal
    int i_LastSignal = -1;
}

//*************************************************************************************
// Signal Handler
//*************************************************************************************

// Prevent name wrangling
extern "C"
{
    void SignalHandler(int i_Signal)
    {
        switch (i_Signal)
        {
            case SIGILL:
            case SIGTRAP:
            case SIGFPE:
            case SIGABRT:
            case SIGSEGV:
                MRH_PSBLogger::Singleton().Backtrace(25, "Caught Signal: " + std::to_string(i_Signal));
                exit(EXIT_FAILURE);
                break;
                
            case SIGTERM:
                i_LastSignal = i_Signal;
                break;
                
            default:
                i_LastSignal = -1;
                break;
        }
    }
}

//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

libmrhpsb::libmrhpsb(std::string const& s_Identifier,
                     int argc,
                     const char* argv[],
                     size_t us_ThreadCount,
                     bool b_AddDefault) : p_EventHandler(NULL),
                                          p_ThreadPool(NULL)
{
    // Log Setup
    MRH_PSBLogger& c_Logger = MRH_PSBLogger::Singleton();
    c_Logger.OpenFiles(s_Identifier);
    
    c_Logger.Log(MRH_PSBLogger::INFO, "==============================================================", "Main.cpp", __LINE__);
    c_Logger.Log(MRH_PSBLogger::INFO, "= Started " + s_Identifier + " Platform Service", "Main.cpp", __LINE__);
    c_Logger.Log(MRH_PSBLogger::INFO, "==============================================================", "Main.cpp", __LINE__);

        
    c_Logger.Log(MRH_PSBLogger::INFO, "Initializing platform service base version " +
                                      std::to_string(MRH_PLATFORM_SERVICE_BASE_LIB_VERSION_MAJOR) +
                                      "." +
                                      std::to_string(MRH_PLATFORM_SERVICE_BASE_LIB_VERSION_MINOR) +
                                      "." +
                                      std::to_string(MRH_PLATFORM_SERVICE_BASE_LIB_VERSION_PATCH) +
                                      "...",
                 "libmrhpsb.cpp", __LINE__);
        
    // Check params
    if (argc < MRH_PARAM_COUNT)
    {
        throw MRH_PSBException("Missing platform service binary parameters!");
    }
        
    // Print mrhevlib info
    c_Logger.Log(MRH_PSBLogger::INFO, "Using mrhevlib version " +
                                      std::to_string(MRH_EV_LIB_VERSION_MAJOR) +
                                      "." +
                                      std::to_string(MRH_EV_LIB_VERSION_MINOR) +
                                      "." +
                                      std::to_string(MRH_EV_LIB_VERSION_PATCH) +
                                      ".",
                 "libmrhpsb.cpp", __LINE__);
    
#ifdef __MRH_MRHCKM_SUPPORTED__
    c_Logger.Log(MRH_PSBLogger::INFO, "Event transmission method: MRHCKM.",
                 "libmrhpsb.cpp", __LINE__);
#else
    c_Logger.Log(MRH_PSBLogger::INFO, "Event transmission method: Pipe.",
                 "libmrhpsb.cpp", __LINE__);
#endif
        
    // Install signal handlers
    std::signal(SIGTERM, SignalHandler);
    std::signal(SIGILL, SignalHandler);
    std::signal(SIGTRAP, SignalHandler);
    std::signal(SIGFPE, SignalHandler);
    std::signal(SIGABRT, SignalHandler);
    std::signal(SIGSEGV, SignalHandler);
        
    // Setup components
    try
    {
#ifdef __MRH_MRHCKM_SUPPORTED__
        p_EventHandler = new MRH_EventHandler(argv[MRH_PARAM_EV_INPUT_FD],
                                              argv[MRH_PARAM_EV_INPUT_KEY],
                                              argv[MRH_PARAM_EV_OUTPUT_FD],
                                              argv[MRH_PARAM_EV_OUTPUT_KEY],
                                              argv[MRH_PARAM_EV_EVENT_LIMIT],
                                              argv[MRH_PARAM_EV_TIMEOUT_MS]);
#else
        p_EventHandler = new MRH_EventHandler(argv[MRH_PARAM_EV_INPUT_FD],
                                              argv[MRH_PARAM_EV_OUTPUT_FD],
                                              argv[MRH_PARAM_EV_EVENT_LIMIT],
                                              argv[MRH_PARAM_EV_TIMEOUT_MS]);
#endif
        p_ThreadPool = new MRH_ThreadPool(us_ThreadCount,
                                          b_AddDefault);
    }
    catch (MRH_PSBException& e)
    {
        throw;
    }
    catch (std::exception& e)
    {
        throw MRH_PSBException(e.what());
    }
}

libmrhpsb::~libmrhpsb() noexcept
{
    if (p_ThreadPool != NULL)
    {
        delete p_ThreadPool;
    }
    
    if (p_EventHandler != NULL)
    {
        delete p_EventHandler;
    }
}

//*************************************************************************************
// Add
//*************************************************************************************

void libmrhpsb::AddCallback(std::shared_ptr<MRH_Callback>& p_Callback, MRH_Uint32 u32_Type)
{
    if (p_Callback == NULL || IsValidEventType(u32_Type) == false)
    {
        throw MRH_PSBException("Invalid callback!");
    }
    
    try
    {
        p_ThreadPool->AddCallback(p_Callback, u32_Type);
    }
    catch (MRH_PSBException& e)
    {
        throw;
    }
}

//*************************************************************************************
// Update
//*************************************************************************************

void libmrhpsb::Update() noexcept
{
    // Exchange events until termination
    MRH_PSBLogger& c_Logger = MRH_PSBLogger::Singleton();
    
    while (i_LastSignal != SIGTERM)
    {
        // Recieve events
        std::vector<MRH_Event*>& v_Recieved = p_EventHandler->RecieveEvents();
        
        for (auto Event = v_Recieved.begin(); Event != v_Recieved.end();)
        {
            try
            {
                MRH_EVBase* p_Base = libmrhcevs::Create(*Event);
                p_ThreadPool->AddJob(p_Base, (*Event)->u32_GroupID);
                
                if ((*Event)->p_Data != NULL)
                {
                    free((*Event)->p_Data);
                }
                
                free(*Event);
                
                Event = v_Recieved.erase(Event);
            }
            catch (MRH_CEVSException& e)
            {
                c_Logger.Log(MRH_PSBLogger::WARNING, "Failed to add job (CEVS): " + e.what2(),
                             "libmrhpsb.cpp", __LINE__);
                ++Event;
            }
            catch (MRH_PSBException& e)
            {
                c_Logger.Log(MRH_PSBLogger::WARNING, "Failed to add job: " + e.what2(),
                             "libmrhpsb.cpp", __LINE__);
                ++Event;
            }
        }
        
        // Send events
        p_EventHandler->SendEvents();
    }
}

//*************************************************************************************
// Getters
//*************************************************************************************

bool libmrhpsb::IsValidEventType(MRH_Uint32 u32_Type) noexcept
{
    switch (u32_Type)
    {
        /* Event Version 1 */
            
        case MRH_EVENT_UNK:
        case MRH_EVENT_PERMISSION_DENIED:
        case MRH_EVENT_PASSWORD_REQUIRED:
        case MRH_EVENT_NOT_IMPLEMENTED_S:
        case MRH_EVENT_PS_RESET_ACKNOLEDGED_U:
        case MRH_EVENT_CUSTOM_CUSTOM_COMMAND_S:
        case MRH_EVENT_LISTEN_AVAIL_S:
        case MRH_EVENT_LISTEN_STRING_S:
        case MRH_EVENT_LISTEN_GET_METHOD_S:
        case MRH_EVENT_LISTEN_CUSTOM_COMMAND_S:
        case MRH_EVENT_SAY_AVAIL_S:
        case MRH_EVENT_SAY_STRING_S:
        case MRH_EVENT_SAY_GET_METHOD_S:
        case MRH_EVENT_SAY_CUSTOM_COMMAND_S:
        case MRH_EVENT_PASSWORD_AVAIL_S:
        case MRH_EVENT_PASSWORD_CHECK_S:
        case MRH_EVENT_PASSWORD_SET_S:
        case MRH_EVENT_PASSWORD_CUSTOM_COMMAND_S:
        case MRH_EVENT_USER_AVAIL_S:
        case MRH_EVENT_USER_ACCESS_DOCUMENTS_S:
        case MRH_EVENT_USER_ACCESS_PICTURES_S:
        case MRH_EVENT_USER_ACCESS_MUSIC_S:
        case MRH_EVENT_USER_ACCESS_VIDEOS_S:
        case MRH_EVENT_USER_ACCESS_DOWNLOADS_S:
        case MRH_EVENT_USER_ACCESS_CLIPBOARD_S:
        case MRH_EVENT_USER_ACCESS_INFO_PERSON_S:
        case MRH_EVENT_USER_ACCESS_INFO_RESIDENCE_S:
        case MRH_EVENT_USER_ACCESS_CLEAR_S:
        case MRH_EVENT_USER_GET_LOCATION_S:
        case MRH_EVENT_USER_CUSTOM_COMMAND_S:
        case MRH_EVENT_APP_AVAIL_S:
        case MRH_EVENT_APP_LAUNCH_SOA_S:
        case MRH_EVENT_APP_LAUNCH_SOA_TIMER_S:
        case MRH_EVENT_APP_LAUNCH_SOA_TIMER_REMINDER_S:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_S:
        case MRH_EVENT_APP_LAUNCH_SOA_CLEAR_TIMER_S:
        case MRH_EVENT_APP_CUSTOM_COMMAND_S:
        case MRH_EVENT_NOTIFICATION_AVAIL_S:
        case MRH_EVENT_NOTIFICATION_CREATE_APP_S:
        case MRH_EVENT_NOTIFICATION_DESTROY_APP_S:
        case MRH_EVENT_NOTIFICATION_GET_WAITING_S:
        case MRH_EVENT_NOTIFICATION_GET_NEXT_S:
        case MRH_EVENT_NOTIFICATION_CUSTOM_COMMAND_S:
            return false;
            
        /* Default */
            
        default:
            return true;
    }
}
