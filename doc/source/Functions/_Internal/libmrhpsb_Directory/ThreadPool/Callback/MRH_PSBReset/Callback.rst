Callback
========
The Callback function is called by a worker thread with a reset request event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/ThreadPool/Callback/MRH_PSBReset.h"


Syntax
------
.. code-block:: c

    void Callback(const MRH_EVBase* p_Event,
                  MRH_Uint32 u32_GroupID) noexcept override;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Event
      - The event which triggered this callback.
    * - u32_GroupID
      - The user event group id for the recieved user event.


Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.