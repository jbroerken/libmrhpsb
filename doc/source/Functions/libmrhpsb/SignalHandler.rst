SignalHandler
=============
The SignalHandler function is used to intercept and handle signals like SIGINT.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    libmrhpsb.cpp


Syntax
------
.. code-block:: c

    void SignalHandler(int i_Signal);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - i_Signal
      - The recieved signal.
      

Return Value
------------
None.

Remarks
-------
* This function should only be called when recieving an operating system signal.

Code Examples
-------------
None.