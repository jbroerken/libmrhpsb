MRH_EventHandler (Pipe Constructor)
===================================
The Pipe MRH_EventHandler constructor function is used to construct the 
MRH_EventHandler class with Pipe-based event queues.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/MRH_EventHandler.h"


Syntax
------
.. code-block:: c

    MRH_EventHandler(const char* p_InputFD,
                     const char* p_OutputFD,
                     const char* p_EventLimit,
                     const char* p_TimeoutMS);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_InputFD
      - The file descriptor for the input pipe.
    * - p_OutputFD
      - The file descriptor for the output pipe.
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
* This function throws an exception if the construction of the event queues from 
  the given event queue info was not possible or a allocation failed.

Code Examples
-------------
None.