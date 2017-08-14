#include "binaryTree.h"
#include <iostream>

void 


int main( int argc, char* argv[] )
{

	binaryTree familyTree;
	familyTree.insert( 10, "umit aykurt" );
	familyTree.insert( 9, "aysegul hacioglu" );
	familyTree.insert( 5, "berke aykurt" );
	familyTree.insert( 7, "berkay aykurt" );

	std::string value = familyTree.search( 10 );
	std::string value2 = familyTree.search( 5 );

	std::cout<< "Search result for key 10 is " << value <<std::endl;
	

	
	return 0;
}
