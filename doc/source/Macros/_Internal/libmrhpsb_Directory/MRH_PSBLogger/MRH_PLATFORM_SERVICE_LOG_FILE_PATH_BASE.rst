MRH_PLATFORM_SERVICE_LOG_FILE_PATH_BASE
=======================================
The MRH_PLATFORM_SERVICE_LOG_FILE_PATH_BASE macro defines the base file path to 
the log files.

Header
------
The macro definition can be found in the following file:

.. code-block:: c

    libmrhpsb/MRH_PSBLogger.cpp


Definition
----------
The defined log file path in the source is as follows:

.. code-block:: c

    #ifndef MRH_PLATFORM_SERVICE_LOG_FILE_PATH_BASE
    #define MRH_PLATFORM_SERVICE_LOG_FILE_PATH_BASE "/var/log/mrhpservice/mrhpservice_"
    #endif