CC=g++
CFLAGS=-c -fPIC
INCLUDE_PATH=-I./include/
OBJECTS = queue.o iterator.o
LIBNAME = libqueue.so
VPATH = src:tests

all: $(LIBNAME) $(OBJECTS) queueTests.cpp
	$(CC) -g $(INCLUDE_PATH) $^ -o exe

$(LIBNAME): $(OBJECTS)
	$(CC) -shared -o $(LIBNAME) $(OBJECTS)

$(OBJECTS): %.o : %.cpp 
	$(CC) -g $(CFLAGS) $(INCLUDE_PATH) $^ -o $@

.PHONY:install
install:
	if [ -f ./libqueue.so ]; then \
			mv libqueue.so /usr/lib; \
			cp ./include/queue.h /usr/include; \
			cp ./include/iterator.h /usr/include; \
	fi \

.PHONY:clean
clean:
	rm *.o exe \
	if [ -f /usr/lib/libqueue.so ]; then \
		rm /usr/lib/libqueue.so; \
	fi\

.PHONY:cleanLib
cleanLib:
	if [ -f ./libqueue.so ]; then \
		rm ./libqueue.so; \
	fi \

	 

