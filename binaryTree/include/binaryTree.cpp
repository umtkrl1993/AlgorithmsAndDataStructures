#include "binaryTree.h"
#include <iostream>

typedef struct treeNode
{

treeNode( int pkey, const std::string& pvalue )
{
	key = pkey;
	value = pvalue;
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
}

int key;
std::string value;
treeNode* parent;
treeNode* leftChild;
treeNode* rightChild;

}treeNode;



namespace 
{
	
	void inorderWalk( const treeNode* node ) 
	{
		
		if( node == NULL )
		{
			return;
		}
		
		inorderWalk( node->leftChild );
		std::cout << "key is " << node->key << " value is " << node->value<< std::endl;
		inorderWalk( node->rightChild );
	}

	void postorderWalk( const treeNode* node )
	{
		if( node == NULL )
			return;

		postorderWalk( node->leftChild );
		postorderWalk( node->rightChild );
		std::cout << "key is " << node->key << " value is " << node->value<< std::endl;
	}

	void inorderWalkNonRecursive( const treeNode* node )
	{

	}

}


binaryTree::binaryTree()
{
	root = NULL;
	m_size = 0;
}

binaryTree::~binaryTree()
{


}

void binaryTree::insert( int key, const std::string& value )
{

	if( root == NULL )
	{
		treeNode* newNode = new treeNode( key, value );
		root = newNode;
		m_size++;
	}
	else
	{
		treeNode* newNode = new treeNode( key, value );
		treeNode* ptr = root;
		treeNode* parent;

		while ( ptr != NULL )
		{
			parent = ptr;
			if( ptr->key > key )
			{
				ptr = ptr->leftChild;
			}
			else
			{
				ptr = ptr->rightChild;
			}
		}
		
		if( parent->key > key )
		{
			parent->leftChild = newNode;
		}
		else
		{
			parent->rightChild = newNode;
		}
		
		newNode->parent = parent;
		m_size++;
	}
}


std::string binaryTree::search( int key ) const
{
	treeNode* node = root;

	while( node->key != key )
	{

		if( node->key > key )
			node = node->leftChild;
		else
			node = node->rightChild;
	}
	std::string val = node->value;

	return val ;
}



int main()
{

	binaryTree b;
	b.insert( 20, "umit aykurt" );
	b.insert( 40, "berke aykurt" );
	b.insert( 43, "berkay aykurt" );
	b.insert( 59, "burak aykurt" );
	b.insert( 10, "ekpe udoh" );
	b.insert( 14, "jan vesely" );


	const treeNode* root = b.getRoot();
	std::cout << "---------------------------------------Inorder Walk Results-----------------------------------------\n";

	inorderWalk( root );


	std::cout << "---------------------------------------Postorder Walk Results---------------------------------------\n";
	
	postorderWalk( root );


	
	return 0;
}
