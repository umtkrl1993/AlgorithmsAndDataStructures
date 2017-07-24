CC=g++
CFLAGS=-c
INCLUDE_PATH=-I./include/
OBJECTS = queue.o iterator.o

VPATH = src:tests

all:$(OBJECTS) queueTests.cpp
	$(CC) $(INCLUDE_PATH) $^ -o exe

$(OBJECTS): %.o : %.cpp 
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $^ -o $@
