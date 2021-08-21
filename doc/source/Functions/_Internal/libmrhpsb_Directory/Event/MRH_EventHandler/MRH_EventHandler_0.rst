MRH_EventHandler (MRHCKM Constructor)
=====================================
The MRHCKM MRH_EventHandler constructor function is used to construct the 
MRH_EventHandler class with MRHCKM-based event queues.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/MRH_EventHandler.h"


Syntax
------
.. code-block:: c

    MRH_EventHandler(const char* p_InputPath,
                     const char* p_InputKey,
                     const char* p_OutputPath,
                     const char* p_OutputKey,
                     const char* p_EventLimit,
                     const char* p_TimeoutMS);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_InputPath
      - The null terminated full path to the input device file.
    * - p_InputKey
      - The input device file key to access the input file.
    * - p_OutputPath
      - The null terminated full path to the output device file.
    * - p_OutputKey
      - The output device file key to access the output file.
    * - p_EventLimit
      - The send / recieve event limit recieved when starting the application 
        parent.
    * - p_TimeoutMS
      - The event recieve timeout in Milliseconds.


Return Value
------------
None.

Remarks
-------
* This function throws an exception if the construction of the event queues 
  from the given event queue info was not possible or a allocation failed.

Code Examples
-------------
None.