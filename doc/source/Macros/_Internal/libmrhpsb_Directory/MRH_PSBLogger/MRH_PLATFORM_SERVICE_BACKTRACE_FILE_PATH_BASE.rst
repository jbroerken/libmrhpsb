MRH_PLATFORM_SERVICE_BACKTRACE_FILE_PATH_BASE
=============================================
The MRH_PLATFORM_SERVICE_BACKTRACE_FILE_PATH_BASE macro defines the base path 
to the backtrace log files.

Header
------
The macro definition can be found in the following file:

.. code-block:: c

    libmrhpsb/MRH_PSBLogger.cpp


Definition
----------
The defined backtrace file path in the source is as follows:

.. code-block:: c

    #ifndef MRH_PLATFORM_SERVICE_BACKTRACE_FILE_PATH_BASE
    #define MRH_PLATFORM_SERVICE_BACKTRACE_FILE_PATH_BASE "/var/log/mrhpservice/bt_mrhpservice_"
    #endif