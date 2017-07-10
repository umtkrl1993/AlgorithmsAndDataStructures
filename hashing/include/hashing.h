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

//Should I call destructor of struct element because it has not dynamically allocated memory !!
typedef struct hashNode
{
	~hashNode()
	{
		delete e;
	}

	hashNode*next;
	element* e;

}hashNode;

class hashing
{

	public:
	hashing( int p_size );
	virtual void insert( const std::string& key, const std::string& value );
	virtual std::string lookup( const std::string& key );
	virtual int getIndex( const std::string& hashFactor );

	private:
	
	hashNode** m_hashTable;
	int m_size;
};

}

#endif
