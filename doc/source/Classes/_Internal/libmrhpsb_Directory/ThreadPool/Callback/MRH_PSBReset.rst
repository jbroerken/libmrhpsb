MRH_PSBReset
============
The MRH_PSBReset class is used to as a default callback to react to user 
applications signaling a service reset request.

Header
------
The class definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/ThreadPool/Callback/MRH_PSBReset.h"


Functions
---------
.. list-table::
    :header-rows: 1

    * - Function
      - Visibility
    * - :doc:`../../../../../../Functions/_Internal/libmrhpsb_Directory/ThreadPool/Callback/MRH_PSBReset/MRH_PSBReset_0`
      - Public
    * - :doc:`../../../../../../Functions/_Internal/libmrhpsb_Directory/ThreadPool/Callback/MRH_PSBReset/~MRH_PSBReset`
      - Public
    * - :doc:`../../../../../../Functions/_Internal/libmrhpsb_Directory/ThreadPool/Callback/MRH_PSBReset/Callback`
      - Public


Enumerations
------------
None.

Nested Classes
--------------
None.

Inherited Classes
-----------------
.. list-table::
    :header-rows: 1

    * - Class
      - Visibility
    * - :doc:`../../../../libmrhpsb_Directory/MRH_Callback`
      - Public


Variables
---------
None.

Remarks
-------
* This class is used as a default reset request callback. It will update the 
  currently used locale string.