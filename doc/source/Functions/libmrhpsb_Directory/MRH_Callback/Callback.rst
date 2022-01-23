Callback
========
The Callback function is called by a worker thread with the registered event.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_Callback.h>


Syntax
------
.. code-block:: c

    virtual void Callback(const MRH_Event* p_Event,
                          MRH_Uint32 u32_GroupID) noexcept;


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
* This function is meant to be overwritten by the inheriting implementation.

Code Examples
-------------
None.