MRH_EventHandler
================
The MRH_EventHandler class is responsible for communicating with the user 
application. Events are sent and recieved between processes by this class.
The MRH_EventHandler class implements event communication by using the libmrhev 
library.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/Event/MRH_EventHandler.h"


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../Functions/_Internal/libmrhpsb_Directory/Event/MRH_EventHandler/MRH_EventHandler_0`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhpsb_Directory/Event/MRH_EventHandler/MRH_EventHandler_1`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhpsb_Directory/Event/MRH_EventHandler/~MRH_EventHandler`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhpsb_Directory/Event/MRH_EventHandler/SendEvents`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhpsb_Directory/Event/MRH_EventHandler/RecieveEvents`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhpsb_Directory/Event/MRH_EventHandler/Exit`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhpsb_Directory/Event/MRH_EventHandler/GetRemainingEvents`
      - Public
    * - :doc:`../../../../Functions/_Internal/libmrhpsb_Directory/Event/MRH_EventHandler/CheckLibraryError`
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
      - Visibility
    * - p_InputEventQueue
      - MRH_InputEventQueue*
      - The event input queue to read from.
      - Private
    * - p_OutputEventQueue
      - MRH_OutputEventQueue*
      - The event output queue to write to.
      - Private
    * - s32_QueueTimeoutMS
      - MRH_Sint32
      - The timeout in milliseconds to try and read events from the queue.
      - Private
    * - v_Recieved
      - std::vector<MRH_Event*>
      - The storage vector containing all recieved events.
      - Private
    * - us_ReserveStep
      - size_t
      - The amount of space to reserve additionally if the capacity of 
        v_Recieved is filled.
      - Private


Remarks
-------
* This class has a deleted copy constructor.