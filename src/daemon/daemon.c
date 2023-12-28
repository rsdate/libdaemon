/*
Copyright 2023 Rohan Date

libdaemon - a library that
has tools to create and handle 
daemon processes

daemon.c - source code for creating daemon processes. 
Contains the definition of the daemonize() function
protoype as defined in daemon.h

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void daemonize(int (*p)(void)) {
    pid_t pid = 0;
    pid_t sid = 0;
    pid = fork();
    if (pid < 0) {
        printf("fork failed!\n");
        exit(1);
    }

    if (pid > 0) { //its the parent process
        printf("pid of child process %d \n", pid);
        exit(0); //terminate the parent process succesfully
    }

    umask(0);//unmasking the file mode

    sid = setsid();//set new session
    if(sid < 0) {
        exit(1);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    p();
}