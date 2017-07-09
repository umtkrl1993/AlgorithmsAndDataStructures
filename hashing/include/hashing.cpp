#include "hashing.h"
#include<stdio.h>

namespace 
{

const int HASH_FACTOR = 71;

int getIndex( const std::string& key )
{
	int total = 0;
	for( int i = 0; i < key.size(); ++i )
	{
		total += int( key.at( i ) );
	}

	int index = total % HASH_FACTOR;

	return index;
}
}
namespace DataStructures
{

std::string hashing::lookup( const std::string& key )
{
	
	int index = getIndex ( key );
	std::vector< element > chain = hashTable[index];
	std::vector< element >::iterator it = chain.begin();

	for( ; it != chain.end(); ++it )
	{
		if ( ( *it ).key == key )
		{
			return ( *it ).value;
		}
	}

	return " ";
}

void hashing::insert( const std::string& key, const std::string& value )
{
	int index = getIndex( key );
	
	printf( "returned index value is %d \n", index );

	hashTable[index].push_back( element( key, value ) );
}

}


int main()
{

	DataStructures::hashing h;

	h.insert( "umit" , "Computer Engineer" );
	h.insert( "aysegul",  "Electronic Engineer" );

	return 0;
}
