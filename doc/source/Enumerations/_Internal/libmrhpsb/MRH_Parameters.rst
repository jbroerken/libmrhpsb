MRH_Parameters
==============
The MRH_Parameters enumeration is used to define the launch parameters which 
are expected to be passed to the binary when starting the platform service.
The required parameters change depending on the event queue messaging system 
chosen at compilation time.

Header
------
The enumeration definition can be found in the following file:

.. code-block:: c

    libmrhpsb.cpp


Definition
----------
The defined enumeration values are as follows:

.. code-block:: c

    typedef enum
    {
    #ifdef __MRH_MRHCKM_SUPPORTED__
        MRH_PARAM_BIN = 0,
        MRH_PARAM_EV_INPUT_FD = 1,
        MRH_PARAM_EV_INPUT_KEY = 2,
        MRH_PARAM_EV_OUTPUT_FD = 3,
        MRH_PARAM_EV_OUTPUT_KEY = 4,
        MRH_PARAM_EV_EVENT_LIMIT = 5,
        MRH_PARAM_EV_TIMEOUT_MS = 6,

        MRH_PARAM_MAX = 6,

        MRH_PARAM_COUNT = 7
    #else
        MRH_PARAM_BIN = 0,
        MRH_PARAM_EV_INPUT_FD = 1,
        MRH_PARAM_EV_OUTPUT_FD = 2,
        MRH_PARAM_EV_EVENT_LIMIT = 3,
        MRH_PARAM_EV_TIMEOUT_MS = 4,

        MRH_PARAM_MAX = 4,

        MRH_PARAM_COUNT = 5
    #endif
    }MRH_Parameters;


Values
------
The meaning behind the enumeration values is as follows:

.. list-table::
    :header-rows: 1

    * - Enumeration
      - Description
    * - MRH_PARAM_BIN
      - The full path to the application parent binary.
    * - MRH_PARAM_EV_INPUT_FD
      - The pipe or MRHCKM input queue file descriptor
    * - MRH_PARAM_EV_INPUT_KEY
      - The MRHCKM input key for accessing the queue.
    * - MRH_PARAM_EV_OUTPUT_FD
      - The pipe or MRHCKM output queue file descriptor
    * - MRH_PARAM_EV_OUTPUT_KEY
      - The MRHCKM output key for accessing the queue.
    * - MRH_PARAM_EV_EVENT_LIMIT
      - The event limit for recieving / sending events on each update.
    * - MRH_PARAM_EV_TIMEOUT_MS
      - The timeout in milliseconds to wait for incoming events.
    * - MRH_PARAM_MAX
      - The highest possible value of all enumeration values combined.
    * - MRH_PARAM_COUNT
      - The amount of values in this enumeration.