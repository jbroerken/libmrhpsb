/**
 *  MRH_PSBRevision.cpp
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

// C

// External

// Project
#include "../../include/libmrhpsb/libmrhpsb/MRH_PSBRevision.h"


//*************************************************************************************
// Version
//*************************************************************************************

int MRH_PlatformServiceBaseRevision::MRH_GetLibraryVersionMajor() noexcept
{
    return MRH_PLATFORM_SERVICE_BASE_LIB_VERSION_MAJOR;
}

int MRH_PlatformServiceBaseRevision::MRH_GetLibraryVersionMinor() noexcept
{
    return MRH_PLATFORM_SERVICE_BASE_LIB_VERSION_MINOR;
}

int MRH_PlatformServiceBaseRevision::MRH_GetLibraryVersionPatch() noexcept
{
    return MRH_PLATFORM_SERVICE_BASE_LIB_VERSION_PATCH;
}
