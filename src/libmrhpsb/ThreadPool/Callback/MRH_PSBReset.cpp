/**
 *  MRH_PSBReset.cpp
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
#include <clocale>
#include <fstream>
#include <string>

// External
#include <libmrhbf.h>

// Project
#include "./MRH_PSBReset.h"
#include "../../../../include/libmrhpsb/libmrhpsb/MRH_PSBLogger.h"

// Pre-defined
#ifndef MRH_LOCALE_FILE_PATH
    #define MRH_LOCALE_FILE_PATH "/usr/local/etc/mrh/MRH_Locale.conf"
#endif

namespace
{
    // Locale File
    enum LocaleIdentifier
    {
        // Block Name
        LOCALE_BLOCK_LOCALE = 0,

        // Locale Key
        LOCALE_KEY_LOCALE_ACTIVE = 1,
    
        // Bounds
        LOCALE_IDENTIFIER_MAX = LOCALE_KEY_LOCALE_ACTIVE,

        LOCALE_IDENTIFIER_COUNT = LOCALE_IDENTIFIER_MAX + 1
    };

    const char* p_LocaleIdentifier[LOCALE_IDENTIFIER_COUNT] =
    {
        // Block Name
        "Locale",

        // Locale Key
        "Active",
    };

    // Default locale to use
    const char* p_DefaultLocale = "en_US.UTF-8";
}


//*************************************************************************************
// Constructor / Destructor
//*************************************************************************************

MRH_PSBReset::MRH_PSBReset() noexcept
{
    std::setlocale(LC_ALL, p_DefaultLocale);
}

MRH_PSBReset::~MRH_PSBReset() noexcept
{}

//*************************************************************************************
// Callback
//*************************************************************************************

void MRH_PSBReset::Callback(const MRH_EVBase* p_Event, MRH_Uint32 u32_GroupID) noexcept
{
    MRH_PSBLogger& c_Logger = MRH_PSBLogger::Singleton();
    c_Logger.Log(MRH_PSBLogger::INFO, "Reading locale file " +
                                      std::string(MRH_LOCALE_FILE_PATH) +
                                      "...",
                 "MRH_PSBReset.cpp", __LINE__);
    
    try
    {
        MRH_BlockFile c_File(MRH_LOCALE_FILE_PATH);
        
        for (auto& Block : c_File.l_Block)
        {
            if (Block.GetName().compare(p_LocaleIdentifier[LOCALE_BLOCK_LOCALE]) != 0)
            {
                continue;
            }
            
            std::string s_Locale = Block.GetValue(p_LocaleIdentifier[LOCALE_KEY_LOCALE_ACTIVE]);
            std::setlocale(LC_ALL, s_Locale.c_str());
            
            if (s_Locale.compare(std::setlocale(LC_ALL, NULL)) != 0)
            {
                throw MRH_PSBException("Failed to update locale!");
            }
            
            c_Logger.Log(MRH_PSBLogger::INFO, "Locale set to " + s_Locale + ".",
                         "MRH_PSBReset.cpp", __LINE__);
            break;
        }
    }
    catch (std::exception& e) // + MRH_BFException
    {
        c_Logger.Log(MRH_PSBLogger::WARNING, std::string(e.what()) + ", using default locale.",
                     "MRH_PSBReset.cpp", __LINE__);
        std::setlocale(LC_ALL, p_DefaultLocale);
    }
}
