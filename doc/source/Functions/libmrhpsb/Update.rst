Update
======
The Update function is used to start updating the library event communication 
and to perform callbacks.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb.h>


Syntax
------
.. code-block:: c

    void Update() noexcept;


Parameters
----------
None.

Return Value
------------
None.

Remarks
-------
* This function is thread safe.
* This function will not return until the service should be closed.

Code Examples
-------------
None.