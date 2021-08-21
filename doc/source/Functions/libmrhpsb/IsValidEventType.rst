IsValidEventType
================
The IsValidEventType function is used to check if a event type is allowed to be 
used with callbacks.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb.h>


Syntax
------
.. code-block:: c

    bool IsValidEventType(MRH_Uint32 u32_Type) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u32_Type
      - The event type to check.


Return Value
------------
true if the event type can be used, false if not.

Remarks
-------
None.

Code Examples
-------------
None.