AddCallback
===========
The AddCallback function is used to add a callback with a given 
event type to the pool queue.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/ThreadPool/MRH_ThreadPool.h"


Syntax
------
.. code-block:: c

    void AddCallback(std::shared_ptr<MRH_Callback>& p_Callback, 
                     MRH_Uint32 u32_Type);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_Callback
      - The callback to add.
    * - u32_Type
      - The event type for the callback.


Return Value
------------
None.

Remarks
-------
* Existing callbacks for the event type will not be overwritten.

Code Examples
-------------
None.