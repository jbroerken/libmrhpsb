GetLevelString
==============
The GetLevelString function is used to retrieve the description string for 
the current log level value.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_PSBLogger.h>


Syntax
------
.. code-block:: c

    const char* GetLevelString(LogLevel e_Level) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - e_Level
      - The :doc:`../../../Enumerations/libmrhpsb_Directory/MRH_PSBLogger/LogLevel` to get the string for.

Return Value
------------
The current log level string.

Remarks
-------
* This function is thread safe.

Code Examples
-------------
None.