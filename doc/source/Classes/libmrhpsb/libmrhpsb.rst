libmrhpsb
=========
The libmrhpsb class is used to setup and control the libmrhpsb library. The class 
stores callbacks and manages event communication.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb.h>


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../Functions/libmrhpsb/libmrhpsb_0`
      - Public
    * - :doc:`../../Functions/libmrhpsb/~libmrhpsb`
      - Public
    * - :doc:`../../Functions/libmrhpsb/AddCallback`
      - Public
    * - :doc:`../../Functions/libmrhpsb/Update`
      - Public
    * - :doc:`../../Functions/libmrhpsb/IsValidEventType`
      - Private


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
.. list-table::
    :header-rows: 1

    * - Name
      - Type
      - Description
      - Visbility
    * - p_EventHandler
      - MRH_EventHandler*
      - The event communication handler for sending and 
        recieving events.
      - Private
    * - p_ThreadPool
      - MRH_ThreadPool*
      - The thread pool used to perform callbacks for jobs.
      - Private


Remarks
-------
* This class should be constructed first before using any library functionality.