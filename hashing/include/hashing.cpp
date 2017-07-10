#include "hashing.h"
#include<stdio.h>
#include<iostream>

namespace DataStructures
{

hashing::hashing( int p_size )
{
	m_size = p_size;
	mp_hashTable = new hashNode*[ m_size ];

	for( int i = 0; i < m_size; i++ )
	{
		mp_hashTable[i] = NULL;
	}

}

hashing::~hashing()
{
	for( int i = 0; i < m_size; ++i )
	{
		hashNode* deletableNode = mp_hashTable[i];
		hashNode* currentNode = deletableNode;	

		while( ( currentNode != NULL ) && ( currentNode -> mp_next != NULL ) )
		{
			currentNode = deletableNode->mp_next;
			delete deletableNode;
		}	
		
		delete currentNode;
	}

	delete[] mp_hashTable;

}

int hashing::getIndex( const std::string& key )
{
	int total = 0;
	for( int i = 0; i < key.size(); ++i )
	{
		total += int( key.at( i ) );
	}

	int index = ( total % m_size );

	printf( " Key is %s and its calculated hash is %d \n", key.c_str(), index );

	return index;
}

std::string hashing::lookup( const std::string& key )
{
	int index = getIndex ( key );
	hashNode* target = mp_hashTable[index];
	
	while( target->mp_element->m_key != key )
	{	
		target = target->mp_next;
	}

	std::string value = target->mp_element->m_value;

	return value;
}

void hashing::insert( const std::string& key, const std::string& value )
{
	int index = getIndex( key );

	element* newElement = new element( key, value );	
 	hashNode* newNode = new hashNode( newElement );

	if( mp_hashTable[index] == NULL )
	{
		mp_hashTable[index] = newNode;
	}
	else
	{
		hashNode* currentNode = mp_hashTable[index];
		hashNode* previousNode;

		while( currentNode != NULL )
		{
			previousNode = currentNode;
			currentNode = currentNode->mp_next;
		}

		previousNode->mp_next = newNode;
	}
}

}


int main()
{
	
	DataStructures::hashing playerTeamHash(  11 );
	playerTeamHash.insert( "ekpe", "fenerbahce" );
	playerTeamHash.insert( "teo", "cska moscow" );
	playerTeamHash.insert( "decolo", "cska moscow" );
	playerTeamHash.insert( "ayon", "real madrid" );
	playerTeamHash.insert( "yaon", "real madrid" );

	std::string value = playerTeamHash.lookup( "ekpe" );

	std::cout << " ekpe value is " << value << std::endl;

	std::cout << " there should be a collision for ayon and yaon \n";

	value = playerTeamHash.lookup( "yaon" );

	std::cout << "yaon value is " << value << std::endl;
	
	return 0;
}
