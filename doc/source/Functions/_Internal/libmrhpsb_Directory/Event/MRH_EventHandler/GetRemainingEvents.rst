GetRemainingEvents
==================
The GetRemainingEvents function is used to check wether events to send are 
still remaining inside the send vector or not.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/MRH_EventHandler.h"


Syntax
------
.. code-block:: c

    bool GetRemainingEvents() noexcept;


Parameters
----------
None.

Return Value
------------
true if events to be sent are remaining, false if not.

Remarks
-------
None.

Code Examples
-------------
None.