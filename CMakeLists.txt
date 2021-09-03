#########################################################################
#
#  CMAKE
#
#########################################################################

###
#  Minimum Version
#  ---------------
#  The CMake version required.
###
cmake_minimum_required(VERSION 3.1)

###
#  CMake Configuration
#  -------------------
#  Configuration settings for CMake.
#
#  NOTE:
#  These settings have to be applied before the project() setting!
###
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 14)

###
#  Project Info
#  ------------
#  General simple information about our project.
###
project(libmrhpsb VERSION 1.0.0
                  DESCRIPTION "Thread pool based multithreading support library for MRH platform services"
                  LANGUAGES CXX)
set(LIB_SO_VERSION 1)

#########################################################################
#
#  PATHS
#
#########################################################################

###
#  Install Paths
#  -------------
#  GNU system paths for installation.
###
include(GNUInstallDirs)

###
#  Build Paths
#  -----------
#  The paths for the cmake build.
###
set(BUILD_DIR_PATH "${CMAKE_SOURCE_DIR}/build/")
file(MAKE_DIRECTORY ${BUILD_DIR_PATH})

###
#  Source Paths
#  ------------
#  The paths to the source files to use.
###
set(SRC_DIR_PATH "${CMAKE_SOURCE_DIR}/src/")
set(INCLUDE_DIR_PATH "${CMAKE_SOURCE_DIR}/include/")

set(SRC_LIST_DEFAULT_CALLBACK "${SRC_DIR_PATH}/libmrhpsb/ThreadPool/Callback/MRH_PSBReset.cpp"
                              "${SRC_DIR_PATH}/libmrhpsb/ThreadPool/Callback/MRH_PSBReset.h")

set(SRC_LIST_GLOBAL "${SRC_DIR_PATH}/libmrhpsb/ThreadPool/MRH_ThreadPool.cpp"
                    "${SRC_DIR_PATH}/libmrhpsb/ThreadPool/MRH_ThreadPool.h"
                    "${SRC_DIR_PATH}/libmrhpsb/Event/MRH_EventHandler.cpp"
                    "${SRC_DIR_PATH}/libmrhpsb/Event/MRH_EventHandler.h"
                    "${SRC_DIR_PATH}/libmrhpsb/MRH_Callback.cpp"
                    "${SRC_DIR_PATH}/libmrhpsb/MRH_EventStorage.cpp"
                    "${SRC_DIR_PATH}/libmrhpsb/MRH_PSBLogger.cpp"
                    "${SRC_DIR_PATH}/libmrhpsb/MRH_PSBRevision.cpp"
                    "${SRC_DIR_PATH}/libmrhpsb.cpp"
                    "${INCLUDE_DIR_PATH}/libmrhpsb/libmrhpsb/MRH_Callback.h"
                    "${INCLUDE_DIR_PATH}/libmrhpsb/libmrhpsb/MRH_EventStorage.h"
                    "${INCLUDE_DIR_PATH}/libmrhpsb/libmrhpsb/MRH_PSBException.h"
                    "${INCLUDE_DIR_PATH}/libmrhpsb/libmrhpsb/MRH_PSBLogger.h"
                    "${INCLUDE_DIR_PATH}/libmrhpsb/libmrhpsb/MRH_PSBRevision.h"
                    "${INCLUDE_DIR_PATH}/libmrhpsb/libmrhpsb.h")

###
#  Public API Path
#  ---------------
#  The path to the public api include folder.
###
set(PUBLIC_API_DIR_PATH "${INCLUDE_DIR_PATH}/libmrhpsb")
					 
#########################################################################
#
#  TARGET
#
#########################################################################

###
#  Target
#  ------
#  The target(s) to build.
###
add_library(libmrhpsb_Shared SHARED ${SRC_LIST_DEFAULT_CALLBACK}
                                    ${SRC_LIST_GLOBAL})
set_target_properties(libmrhpsb_Shared
                      PROPERTIES
                      PREFIX "lib"
                      OUTPUT_NAME "mrhpsb"
                      SUFFIX ".so"
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${LIB_SO_VERSION})

###
#  Required Libraries
#  ------------------
#  Libraries and / or headers required by this library.
###
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)
find_library(libmrhbf NAMES mrhbf REQUIRED)
find_library(libmrhev NAMES mrhev REQUIRED)
find_library(libmrhcevs NAMES mrhcevs REQUIRED)

target_link_libraries(libmrhpsb_Shared PUBLIC Threads::Threads)
target_link_libraries(libmrhpsb_Shared PUBLIC mrhbf)
target_link_libraries(libmrhpsb_Shared PUBLIC mrhev)
target_link_libraries(libmrhpsb_Shared PUBLIC mrhcevs)

###
#  Source Definitions
#  ------------------
#  Preprocessor source definitions.
###
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_LOCALE_FILE_PATH="/usr/local/etc/mrh/MRH_Locale.conf")
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_PLATFORM_SERVICE_LOG_FILE_PATH_BASE="/var/log/mrh/mrhpservice/mrhpservice_")
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_PLATFORM_SERVICE_BACKTRACE_FILE_PATH_BASE="/var/log/mrh/mrhpservice/bt_mrhpservice_")
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_LOGGER_PRINT_CLI=0)
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_EVENT_STORAGE_RESERVE_STEP=100)

###
#  Install
#  -------
#  Library installation.
###
install(TARGETS libmrhpsb_Shared
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY "${PUBLIC_API_DIR_PATH}/"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h")