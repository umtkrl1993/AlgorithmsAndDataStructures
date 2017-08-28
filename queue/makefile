CC=g++
CFLAGS=-c -fPIC
INCLUDE_PATH=-I./include/
OBJECTS = queue.o iterator.o

VPATH = src:tests

all:$(OBJECTS) queueTests.cpp
	$(CC) -g $(INCLUDE_PATH) $^ -o exe

$(OBJECTS): %.o : %.cpp 
	$(CC) -g $(CFLAGS) $(INCLUDE_PATH) $^ -o $@

clean:
	rm *.o exe
