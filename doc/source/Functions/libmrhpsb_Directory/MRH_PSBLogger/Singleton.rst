Singleton
=========
The Singleton function is used to recieve the single instance of the logger.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_PSBLogger.h>


Syntax
------
.. code-block:: c

    static Logger& Singleton() noexcept;


Parameters
----------
None.

Return Value
------------
The singleton instance of the logger class.

Remarks
-------
* This function is thread safe.

Code Examples
-------------
None.