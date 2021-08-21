Log
===
The Log function is used to log a message to file.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_PSBLogger.h>


Syntax
------
.. code-block:: c

    void Log(LogLevel e_Level, 
             std::string s_Message, 
             std::string s_File, 
             size_t us_Line) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - e_Level
      - The :doc:`../../../Enumerations/libmrhpsb_Directory/MRH_PSBLogger/LogLevel` to use.
    * - s_Message
      - The log message string.
    * - s_File
      - The null terminated name of the file where the log message originated.
    * - us_Line
      - The file line where the log message originated.
      

Return Value
------------
None.

Remarks
-------
* All log messages will be written to the same log file.
* The log file will be kept open due to the FSRoot feature.
* This function is thread safe.

Code Examples
-------------
None.