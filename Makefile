VERSION := 0.0.1
DIST_NAME := libdaemon-${VERSION}

all: daemon

daemon: ./src/daemon/daemon.c
	@mkdir ./lib/
	@clang -c $^
	@ar -rc lib$@.a $@.o
	@mv lib$@.a ./lib/lib$@.a
	@rm -rf $@.o
	@echo libdaemon compiled successfully!

install: ./lib/libdaemon.a ./include/daemon.h
	@cp ./lib/libdaemon.a /usr/local/lib/libdaemon.a
	@cp ./include/daemon.h /usr/local/include/daemon.h
	@echo libdaemon installed successfully!

dist: ./LICENSE ./README.md ./lib/ ./include/ ./Makefile ./src/
	@tar -cf ${DIST_NAME}.tar ./include/ ./lib/ ./src/ ./LICENSE ./README.md ./Makefile
	@gzip ${DIST_NAME}.tar
	@echo libdaemon distrubution created successfully!
