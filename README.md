# libmrhpsb

<p align="center">
<img width="100%" height="100%" src="/doc/source/banner.png">
</p>


## About

The libmrhpsb library is used for platform service development. It includes the event send 
loop as well as a callback structure which allows to react to events.


## Requirements

#### Compilation

This project is built using CMake. You can find CMake here:

https://cmake.org/

#### Library Dependencies

This project requires other libraries and headers to function:

Dependency | Source
---------- | ------
libmrhbf | https://github.com/jbroerken/libmrhbf/
libmrhevdata | https://github.com/jbroerken/libmrhevdata/
libmrhev | https://github.com/jbroerken/libmrhev/
mrhshared | https://github.com/jbroerken/mrhshared/

For more information about the requirements, check the "Building" section found in the documentation.


## Documentation

All documentation is build with sphinx-doc using the Read The Docs theme.
To build the documentation, grab the requirements for it:

#### sphinx-doc
https://www.sphinx-doc.org/en/master/

#### Read The Docs Theme
https://sphinx-rtd-theme.readthedocs.io/en/stable/

## Licence

This project is licenced under the ZLib licence. 
Please read the included LICENCE.txt for the exact terms.


## Directories

This project supplies multiple directories for the development of said project. 
Their names and descriptions are as follows:

Directory | Description
--------- | -----------
build | CMake build directory.
doc | Documentation files.
include | The project headers.
src | Project source code.
