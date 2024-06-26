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
to libdaemon's [official github repository](https://www.github.com/rsdate/libdaemon) and navigate to Releases. Once you have installed the tarball, then decompress it and run the following commands to build and install the library:
```
cd libdaemon-0.0.1
make 
sudo make install
```
After the ```make``` step, you will see ```libdaemon compiled
successfully``` in your terminal window if libdaemon was compiled successfully. After
the ```make install``` step, the message ```libdaemon installed successfully!``` will be printed to your terminal
if the installation was successful.
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
In order to actually use the library, you will need to link it with the program.
Use the commands below to link the library with your program:
```
$CC main.c -Wall -Werror -ldaemon -o main
```
When you run you project, it will run as a daemon process
and in the backround. The library will also print the pid 
(process id) of the daemon process.
## Notes
* In the above section, replace ```$CC``` with you preferred C compiler.
