OpenFiles
=========
The OpenFiles function is used to create files to write logging information to.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_PSBLogger.h>


Syntax
------
.. code-block:: c

    void OpenFiles(std::string const& s_ServiceName) noexcept;


Parameters
----------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - s_ServiceName
      - The service name to log for,
      

Return Value
------------
None.

Remarks
-------
* This function will close older opened files.
* The stored service name will be changed.

Code Examples
-------------
None.