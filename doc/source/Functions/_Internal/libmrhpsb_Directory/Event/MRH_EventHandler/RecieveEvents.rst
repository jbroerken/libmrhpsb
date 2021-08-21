RecieveEvents
=============
The RecieveEvents function is used to recieve events from the current user 
application.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/MRH_EventHandler.h"


Syntax
------
.. code-block:: c

    std::vector<MRH_Event*>& RecieveEvents() noexcept;


Parameters
----------
None.     

Return Value
------------
The vector containing all recieved events.

Remarks
-------
* libmrhev is used to recieve events.
* Events will be recieved until the libmrhev recieve function has no more 
  events to be recieved or the set event limit was reached.

Code Examples
-------------
None.