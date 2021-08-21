MRH_Callback
============
The MRH_Callback class is used to give a basic callback structure which is then 
calles by the library if an event matching a registered callback is recieved.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_Callback.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_Callback/~MRH_Callback`
      - Public
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_Callback/Callback`
      - Public
    * - :doc:`../../Functions/libmrhpsb_Directory/MRH_Callback/MRH_Callback_0`
      - Protected


Enumerations
------------
None.

Nested Classes
--------------
None.

Inherited Classes
-----------------
None.

Variables
---------
None.

Remarks
-------
* This class can only be constructed be the class inheriting.
* The Callback function is meant to be overwriten since the library calls this 
  function with a base class pointer.