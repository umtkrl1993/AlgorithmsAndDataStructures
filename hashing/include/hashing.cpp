#include "hashing.h"
#include<stdio.h>

namespace DataStructures
{

hashing::hashing( int p_size )
{
	m_size = p_size;
	hashTable = new hashTable*[ m_size ];

	for( int i = 0; i < m_size; i++ )
	{
		hashTable[i] = NULL;
	}

}

int hashing::getIndex( const std::string& key )
{
	int total = 0;
	for( int i = 0; i < key.size(); ++i )
	{
		total += int( key.at( i ) );
	}

	int index = total % m_size;

	return index;
}

std::string hashing::lookup( const std::string& key )
{
	
	int index = getIndex ( key );

	return " ";
}

void hashing::insert( const std::string& key, const std::string& value )
{
	int index = getIndex( key );
	
	if( hashTable[index] == NULL )
	{
		
	} 
}

}


int main()
{

	DataStructures::hashing h;

	h.insert( "umit" , "Computer Engineer" );
	h.insert( "aysegul",  "Electronic Engineer" );

	return 0;
}
