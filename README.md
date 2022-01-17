
# Overview

This repository contains a Qt application which facilitates generating UUID's
from Qt's QUuid class.  This application provides an interface for generating
a UUID and then saving it to a table. 

![qtUuidFactory](/assets/screenrecording.gif)

# Dependencies
The application was written in C++ (17) using Qt5. It was built using CMake 3.20.4.


# Building:
In order to build the application, create a directory (.e.g. build) from which CMake will be executed. The process below can be used to build the application.

* `git clone https://github.com/bruckart/qtUuidFactory.git`
* `cd qtUuidFactory`
* `mkdir build`
* `cd build`
* `cmake ../`
* `make`
* `./qtUuidFactory`


# References/Credits:

* [Qt's QUuid Class Reference](https://doc.qt.io/qt-5/quuid.html)