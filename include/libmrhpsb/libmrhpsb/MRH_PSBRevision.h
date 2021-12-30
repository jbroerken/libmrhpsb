/**
 *  MRH_PSBRevision.h
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

#ifndef MRH_PSBRevision_h
#define MRH_PSBRevision_h

// C / C++

// External

// Project


namespace MRH_PlatformServiceBaseRevision
{

    //*************************************************************************************
    // Version
    //*************************************************************************************

    /**
     *  Get the library major version number.
     *
     *  \return The library major version number.
     */

    int MRH_GetLibraryVersionMajor() noexcept;

    /**
     *  Get the library minor version number.
     *
     *  \return The library minor version number.
     */

    int MRH_GetLibraryVersionMinor() noexcept;

    /**
     *  Get the library patch version number.
     *
     *  \return The library patch version number.
     */

    int MRH_GetLibraryVersionPatch() noexcept;
}

//*************************************************************************************
// Revision
//*************************************************************************************

#define MRH_PLATFORM_SERVICE_BASE_LIB_VERSION_MAJOR 1
#define MRH_PLATFORM_SERVICE_BASE_LIB_VERSION_MINOR 0
#define MRH_PLATFORM_SERVICE_BASE_LIB_VERSION_PATCH 0


#endif /* MRH_PSBRevision_h */
