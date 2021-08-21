Backtrace
=========
The Backtrace function is used to create a backtrace log file using date and 
time information for the file name.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_PSBLogger.h>


Syntax
------
.. code-block:: c

    void Backtrace(size_t us_TraceSize, 
                   std::string s_Message) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - us_TraceSize
      - The amount of steps stored in the log file.
    * - s_Message
      - The log message string defining the backtrace log.
      

Return Value
------------
None.

Remarks
-------
* The time and date used are matching the start of the program due to the 
  FSRoot feature.
* The backtrace file will be kept open due to the FSRoot feature.
* The mutex lock is not used for this function to protect against a endless 
  lock if a signal was recieved during the logging process.

Code Examples
-------------
None.