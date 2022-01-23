AddJob
======
The AddJob function is used to add a event to the job list.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/ThreadPool/MRH_ThreadPool.h"


Syntax
------
.. code-block:: c

    void AddJob(MRH_Event* p_Event, MRH_Uint32 u32_GroupID);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event to add as a job.
    * - u32_GroupID
      - The group id for the event job.


Return Value
------------
None.

Remarks
-------
* The given event is consumed.

Code Examples
-------------
None.