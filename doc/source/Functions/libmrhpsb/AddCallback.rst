AddCallback
===========
The AddCallback function is used to add a new callback for an event type.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb.h>


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
      - The event type this callback is used for.


Return Value
------------
None.

Remarks
-------
* This function is thread safe.
* An exception is thrown if the callback or event type is invalid.
* Old callbacks for the given event type will not be overwritten.

Code Examples
-------------
None.