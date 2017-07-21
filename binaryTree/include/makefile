CC=g++
LIBRARY_PATH=/usr/local/lib/cppDSAndAlgo

exe: binaryTreeTest.cpp libBinaryTree
	@$(CC) -L$(LIBRARY_PATH) binaryTreeTest.cpp -o exe -lbinarytree

libBinaryTree: binaryTreeObjectFile
	@if [ ! -f /usr/local/lib/cppDSAndAlgo/libbinarytree.so ]; then \
		$(CC) -shared binaryTree.o -o libbinarytree.so;\
		echo "libbinarytree was not found , created ";\
		cp libbinarytree.so /usr/local/lib/cppDSAndAlgo; \
	else \
		echo "libbinarytree is already created";\
	fi\
		
binaryTreeObjectFile: binaryTree.cpp
	@$(CC) -c -fPIC binaryTree.cpp -o binaryTree.o

clean:
	rm -rf exe binaryTree.o libbinarytree.so


