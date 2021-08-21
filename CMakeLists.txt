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
project(libmrhpsb VERSION 1.0
                  DESCRIPTION "Thread pool based multithreading support library for MRH platform services"
                  LANGUAGES CXX)

#########################################################################
#
#  PATHS
#
#########################################################################

###
#  Binary Paths
#  ------------
#  The paths for our created binary file(s).
###
set(BIN_DIR_PATH "${CMAKE_SOURCE_DIR}/lib/")
file(MAKE_DIRECTORY ${BIN_DIR_PATH})

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
#  Library Paths
#  -------------
#  The paths to the external libraries to use. 
#  Both the binary and include paths should be set here.
#  Add OS specific libraries in their own lists.
###
set(LIB_DIR_PATH "${CMAKE_SOURCE_DIR}/lib/")
# Include dir path is defined with the sources!

set(LIB_BIN_LIST "${LIB_DIR_PATH}/libmrhev.a"
                 "${LIB_DIR_PATH}/libmrhcevs.a"
                 "${LIB_DIR_PATH}/libmrhbf.a")
set(LIB_INCLUDE_LIST "${INCLUDE_DIR_PATH}/mrhshared"
					 "${INCLUDE_DIR_PATH}/libmrhev"
					 "${INCLUDE_DIR_PATH}/libmrhcevs"
					 "${INCLUDE_DIR_PATH}/libmrhbf")
					 
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
					  PREFIX ""
					  OUTPUT_NAME "libmrhpsb"
					  SUFFIX ".so"
    				  ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
    				  LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
    				  RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR_PATH})
					  
add_library(libmrhpsb_Static STATIC ${SRC_LIST_DEFAULT_CALLBACK}
					   			    ${SRC_LIST_GLOBAL})
set_target_properties(libmrhpsb_Static
    				  PROPERTIES
					  PREFIX ""
					  OUTPUT_NAME "libmrhpsb"
					  SUFFIX ".a"
    				  ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
    				  LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR_PATH}
    				  RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR_PATH})

###
#  Required Libraries
#  ------------------
#  Libraries and / or headers required by this library.
###
target_link_libraries(libmrhpsb_Shared PUBLIC ${LIB_BIN_LIST})
target_link_libraries(libmrhpsb_Static PUBLIC ${LIB_BIN_LIST})
include_directories(${LIB_INCLUDE_LIST})

###
#  Source Definitions
#  ------------------
#  Preprocessor source definitions.
###
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_LOCALE_FILE_PATH="/etc/MRH_Locale.conf")
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_PLATFORM_SERVICE_LOG_FILE_PATH_BASE="/var/log/mrh/mrhpservice/mrhpservice_")
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_PLATFORM_SERVICE_BACKTRACE_FILE_PATH_BASE="/var/log/mrh/mrhpservice/bt_mrhpservice_")
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_LOGGER_PRINT_CLI=0)
target_compile_definitions(libmrhpsb_Shared PRIVATE MRH_EVENT_STORAGE_RESERVE_STEP=100)

target_compile_definitions(libmrhpsb_Static PRIVATE MRH_LOCALE_FILE_PATH="/etc/MRH_Locale.conf")
target_compile_definitions(libmrhpsb_Static PRIVATE MRH_PLATFORM_SERVICE_LOG_FILE_PATH_BASE="/var/log/mrh/mrhpservice/mrhpservice_")
target_compile_definitions(libmrhpsb_Static PRIVATE MRH_PLATFORM_SERVICE_BACKTRACE_FILE_PATH_BASE="/var/mrh/log/mrhpservice/bt_mrhpservice_")
target_compile_definitions(libmrhpsb_Static PRIVATE MRH_LOGGER_PRINT_CLI=0)
target_compile_definitions(libmrhpsb_Static PRIVATE MRH_EVENT_STORAGE_RESERVE_STEP=100)