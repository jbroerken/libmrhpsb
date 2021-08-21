Exit
====
The Exit function is used to close all event queue connections and remove all 
remaining event data.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/MRH_EventHandler.h"


Syntax
------
.. code-block:: c

    void Exit() noexcept;


Parameters
----------
None.

Return Value
------------
None.

Remarks
-------
* All remaining events inside the recieve vector will be deallocated.
* This function is also called by the destructor.

Code Examples
-------------
None.