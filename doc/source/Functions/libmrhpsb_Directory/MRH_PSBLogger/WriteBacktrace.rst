WriteBacktrace
==============
The WriteBacktrace function is used to add a backtrace step to the backtrace 
file.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_PSBLogger.h>


Syntax
------
.. code-block:: c

    void WriteBacktrace(std::ofstream& f_File, 
                        std::string s_Message) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - f_File
      - The reference to the opened backtrace file to write to.
    * - s_Message
      - The log message string.
      

Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.