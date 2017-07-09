#ifndef _HASHING_H
#define _HASHING_H

#include<string>
#include<vector>
namespace DataStructures
{

typedef struct element
{
	element( const std::string& pkey, const std::string& pvalue )
	{
		key = pkey;
		value = pvalue;
	}
	std::string key;
	std::string value;

}element;

class hashing
{

	public:
	virtual void insert( const std::string& key, const std::string& value );
	virtual std::string lookup( const std::string& key );

	private:
	std::vector< std::vector< element > > hashTable;
	

};

}


#endif
