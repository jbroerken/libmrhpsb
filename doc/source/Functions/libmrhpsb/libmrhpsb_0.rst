libmrhpsb (Default Constructor)
===============================
The default libmrhpsb constructor function is used to construct the libmrhpsb 
class. The constructor will start the library thread pool.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb.h>


Syntax
------
.. code-block:: c

    libmrhpsb(std::string const& s_Identifier,
              int argc,
              const char* argv[],
              size_t us_ThreadCount);


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_Identifier
      - The identifier for this service.
    * - argc
      - The binary argument count.
    * - argv
      - The binary argument list.
    * - us_ThreadCount
      - The number of threads to use for callback performing.
      

Return Value
------------
None.

Remarks
-------
None.

Code Examples
-------------
None.