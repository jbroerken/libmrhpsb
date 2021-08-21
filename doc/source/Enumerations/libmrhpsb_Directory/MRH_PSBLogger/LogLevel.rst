LogLevel
========
The LogLevel enumeration is used to describe the type of message to be logged.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    #include <libmrhpsb/MRH_PSBLogger.h>


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
        INFO = 0,
        WARNING = 1,
        ERROR = 2,
        
        LOG_LEVEL_MAX = 2,
        
        LOG_LEVEL_COUNT = 3
        
    }LogLevel;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - INFO
      - The logged message is a simple information.
    * - WARNING
      - The logged message is a warning.
    * - ERROR
      - The logged message is an error.
    * - LOG_LEVEL_MAX
      - The highest level value in this enumeration.
    * - LOG_LEVEL_COUNT
      - The amount of level values in this enumeration.