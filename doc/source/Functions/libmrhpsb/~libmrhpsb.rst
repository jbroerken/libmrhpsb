~libmrhpsb
==========
The ~libmrhpsb function is the default destructor for the libmrhpsb class.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb.h>


Syntax
------
.. code-block:: c

    ~libmrhpsb() noexcept;


Parameters
----------
None.

Return Value
------------
None.

Remarks
-------
* The destructor will wait until all threads are stopped.

Code Examples
-------------
None.