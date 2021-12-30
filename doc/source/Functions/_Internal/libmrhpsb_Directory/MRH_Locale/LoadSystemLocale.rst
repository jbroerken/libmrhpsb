LoadSystemLocale
================
The LoadSystemLocale function is used to read the set system locale 
and set it for the library user.

Header
------
The function definition can be found in the following file:

.. code-block:: c

    #include "libmrhpsb/MRH_Locale.h"


Syntax
------
.. code-block:: c

    void LoadSystemLocale() noexcept;


Parameters
----------
None.

Return Value
------------
None.

Remarks
-------
* The en_US.UTF-8 locale is used if configuration loading failed.

Code Examples
-------------
None.