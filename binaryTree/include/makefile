CC=g++

exe: binaryTreeTest.cpp libBinaryTree
	$(CC) -L/usr/local/lib/algorithms binaryTreeTest.cpp -o exe -lbinarytree

libBinaryTree: binaryTreeObjectFile
	$(CC) -shared binaryTree.o -o libbinarytree.so

binaryTreeObjectFile: binaryTree.cpp
	$(CC) -c -fPIC binaryTree.cpp -o binaryTree.o

clean:
	rm -rf exe binaryTree.o libbinarytree.so

