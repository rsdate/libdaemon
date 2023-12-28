/*
Copyright 2023 Rohan Date

libdaemon - a library that
has tools to create and handle 
daemon processes

daemon.h - header file to include in your project
that contains the daemonize() function prototype
*/

#ifndef __DAEMON_H__
#define __DAEMON_H__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void daemonize(int (*p)(void));

#endif