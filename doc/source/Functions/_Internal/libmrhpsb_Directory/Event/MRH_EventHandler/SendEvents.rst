SendEvents
==========
The SendEvent function is used to send events from the global event storage
container. These events are sent together with already existing events waiting 
to be sent.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/MRH_EventHandler.h"


Syntax
------
.. code-block:: c

    void SendEvents() noexcept;


Parameters
----------
None.

Return Value
------------
None.

Remarks
-------
* All events from the gobal event storage container will be added.
* Events will be send until the global event storage container is emptied or 
  the event limit is reached.

Code Examples
-------------
None.