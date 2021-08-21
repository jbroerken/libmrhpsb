MRH_PSBLogger
=============
The MRH_PSBLogger class is used to log messages and backtrace information.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_PSBLogger>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_PSBLogger/Singleton`
      - Public
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_PSBLogger/OpenFiles`
      - Public
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_PSBLogger/Log`
      - Public
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_PSBLogger/Backtrace`
      - Public
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_PSBLogger/MRH_PSBLogger_0`
      - Private
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_PSBLogger/~MRH_PSBLogger`
      - Private
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_PSBLogger/WriteBacktrace`
      - Private
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_PSBLogger/GetLevelString`
      - Private


Enumerations
------------
.. list-table::
    :header-rows: 1

    * - Enumeration
      - Visibility
    * - :doc:`../../Enumerations/libmrhpsb_Directory/MRH_PSBLogger/LogLevel`
      - Public


Nested Classes
--------------
None.

Inherited Classes
-----------------
None.

Variables
---------
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visbility
    * - c_Mutex
      - std::mutex
      - The mutex lock for multithreading.
      - Private
    * - s_ServiceName
      - std::string
      - The service name to log for.
      - Private
    * - f_LogFile
      - std::ofstream
      - The message log file in use.
      - Private
    * - f_BacktraceFile
      - std::ofstream
      - The backtrace log file in use.
      - Private


Remarks
-------
* This class starts existing as soon as the singleton function was used.
* This class can not be constructed freely.
* This class exists as a single shared instance.