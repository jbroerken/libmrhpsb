MRH_LOCALE_FILE_PATH
====================
The MRH_LOCALE_FILE_PATH macro defines the full path to the platform locale 
file.

Header
------
The macro definition can be found in the following file:

.. code-block:: c

    libmrhpsb/MRH_Locale.cpp


Definition
----------
The defined locale file path in the source is as follows:

.. code-block:: c

    #ifndef MRH_LOCALE_FILE_PATH
    #define MRH_LOCALE_FILE_PATH "/etc/MRH_Locale.conf"
    #endif