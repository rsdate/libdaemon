# libdaemon

## Introduction
Welcome to libdaemon! libdaemon is a library that can transform
your normal functions into daemon processes. This can include
simple asnychronous IO operations to more large and complex
computing applications that hog a lot a memory and CPU. You can
run multiple functions in parallel to one another, similar to
multi-thread programming. The advantage of a daemon process is
that the OS donates some of its memory to the daemon process, so
that you don't have to worry about memory management.


## Prerequisites
Before installing this library, you will need to install a tool
called **sudo**. This tool allows you to run commands as a
superuser, or a user with elevated permissions. You need this
because this library will be copying source files into standard
locations (/usr/lib, /usr/local/bin, etc.). If you don't already
have it installed, please refer to your operating system's
installation instructions.   

## Installation
### Building from source
If you want to build the library from source, or can't obtain any
pre-built copies of the library, then this section is for you. Go
to libdaemon's [official github repository](https://www.github.com/rsdate/libdaemon) and navigate to Releases. Then decompress the tarball and run the following commands to build and install the library:
```
cd libdaemon-0.0.1
make 
sudo make install
``` 
If the installation is a success, then the message ```libdaemon
installed successfully!``` will be printed to your terminal. 
## Usage
Once you have installed the program, you can include the header
file in your project:
```
...
#include <daemon.h>
...
```
Once you have included the header file in your project, you can
then create a function pointer to the function you want to make a
daemon process. Include these lines at the bottom of your main
function: 
```
...
int (*func_ptr)(void) = &func;
daemonize(func_ptr);
...
```
When you compile your project and run it, your project will run as
a daemon process and in the backround. The library will also print
the pid (process id) of the daemon process.
