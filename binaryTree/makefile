CC=g++
LIBRARY_PATH=/usr/local/lib/cppDSAndAlgo
VPATH=src
INCLUDE_PATH=-I./include/
SOURCE_FILES=binaryTree.cpp
OBJECTS_FILES=binaryTree.o
LIBRARY_FILE = libbinarytree.so


#exe:
#	$(CC) -c $(INCLUDE_PATH) ./src/binaryTree.cpp -o exe
	
#exe: binaryTreeTest.cpp libBinaryTree
#	@$(CC) -L$(LIBRARY_PATH) binaryTreeTest.cpp -o exe -lbinarytree

$(OBJECTS_FILES): %.o : %.cpp
		@if [ ! -d ./bin ]; then \
			mkdir bin/; \
		fi \
		
		$(CC) -c -fPIC $(INCLUDE_PATH) $^ -o $@; \


clean :
	@rm -rf ./bin *.o			
	


