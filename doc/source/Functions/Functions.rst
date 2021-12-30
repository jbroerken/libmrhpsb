*********
Functions
*********
The list of functions shown here includes information about their use case as 
well as the required parameters and return values. Code examples are given if 
deemed neccessary.

Internal functions are used by the library itself. These functions are not 
meant to be used directly for platform service development.

Library Functions
-----------------
.. toctree::
  :maxdepth: 1

  libmrhpsb/SignalHandler
  libmrhpsb/libmrhpsb_0
  libmrhpsb/~libmrhpsb
  libmrhpsb/AddCallback
  libmrhpsb/Update
  libmrhpsb/IsValidEventType
  libmrhpsb_Directory/MRH_EventStorage/MRH_EventStorage_0
  libmrhpsb_Directory/MRH_EventStorage/~MRH_EventStorage
  libmrhpsb_Directory/MRH_EventStorage/Singleton
  libmrhpsb_Directory/MRH_EventStorage/Clear
  libmrhpsb_Directory/MRH_EventStorage/Add_0
  libmrhpsb_Directory/MRH_EventStorage/Add_1
  libmrhpsb_Directory/MRH_EventStorage/RemoveFront
  libmrhpsb_Directory/MRH_EventStorage/GetCount
  libmrhpsb_Directory/MRH_EventStorage/GetEvent
  libmrhpsb_Directory/MRH_Callback/MRH_Callback_0
  libmrhpsb_Directory/MRH_Callback/~MRH_Callback
  libmrhpsb_Directory/MRH_Callback/Callback
  libmrhpsb_Directory/MRH_PSBException/MRH_PSBException_0
  libmrhpsb_Directory/MRH_PSBException/MRH_PSBException_1
  libmrhpsb_Directory/MRH_PSBException/~MRH_PSBException
  libmrhpsb_Directory/MRH_PSBException/what
  libmrhpsb_Directory/MRH_PSBException/what2
  libmrhpsb_Directory/MRH_PSBLogger/MRH_PSBLogger_0
  libmrhpsb_Directory/MRH_PSBLogger/~MRH_PSBLogger
  libmrhpsb_Directory/MRH_PSBLogger/Singleton
  libmrhpsb_Directory/MRH_PSBLogger/OpenFiles
  libmrhpsb_Directory/MRH_PSBLogger/Log
  libmrhpsb_Directory/MRH_PSBLogger/Backtrace
  libmrhpsb_Directory/MRH_PSBLogger/WriteBacktrace
  libmrhpsb_Directory/MRH_PSBLogger/GetLevelString
  libmrhpsb_Directory/MRH_PSBRevision/MRH_GetLibraryVersionMajor
  libmrhpsb_Directory/MRH_PSBRevision/MRH_GetLibraryVersionMinor
  libmrhpsb_Directory/MRH_PSBRevision/MRH_GetLibraryVersionPatch

Internal Functions
------------------
.. toctree::
  :maxdepth: 1
  
  _Internal/libmrhpsb_Directory/ThreadPool/MRH_ThreadPool/MRH_ThreadPool_0
  _Internal/libmrhpsb_Directory/ThreadPool/MRH_ThreadPool/~MRH_ThreadPool
  _Internal/libmrhpsb_Directory/ThreadPool/MRH_ThreadPool/AddCallback
  _Internal/libmrhpsb_Directory/ThreadPool/MRH_ThreadPool/AddJob
  _Internal/libmrhpsb_Directory/ThreadPool/MRH_ThreadPool/Update
  _Internal/libmrhpsb_Directory/Event/MRH_EventHandler/MRH_EventHandler_0
  _Internal/libmrhpsb_Directory/Event/MRH_EventHandler/MRH_EventHandler_1
  _Internal/libmrhpsb_Directory/Event/MRH_EventHandler/~MRH_EventHandler
  _Internal/libmrhpsb_Directory/Event/MRH_EventHandler/SendEvents
  _Internal/libmrhpsb_Directory/Event/MRH_EventHandler/RecieveEvents
  _Internal/libmrhpsb_Directory/Event/MRH_EventHandler/Exit
  _Internal/libmrhpsb_Directory/Event/MRH_EventHandler/GetRemainingEvents
  _Internal/libmrhpsb_Directory/Event/MRH_EventHandler/CheckLibraryError
  _Internal/libmrhpsb_Directory/MRH_Locale/LoadSystemLocale
