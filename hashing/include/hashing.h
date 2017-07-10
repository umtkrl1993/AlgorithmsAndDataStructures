#ifndef _HASHING_H
#define _HASHING_H

#include<string>
#include<vector>
namespace DataStructures
{

typedef struct element
{
	element( const std::string& p_key, const std::string& p_value ):

		m_key( p_key ),
		m_value ( p_value )
	{

	}
	std::string m_key;
	std::string m_value;

}element;

//Should I call destructor of struct element because it has not dynamically allocated memory !!
typedef struct hashNode
{
	hashNode( element* p_element ) 
	{
		mp_element = p_element;
		mp_next = NULL;
	}

	~hashNode()
	{
		delete mp_element;
	}

	hashNode* mp_next;
	element* mp_element;

}hashNode;

class hashing
{

	public:
		hashing( int p_size );
		~hashing();
		virtual void insert( const std::string& key, const std::string& value );
		virtual std::string lookup( const std::string& key );

	protected:
		virtual int getIndex( const std::string& hashFactor );

	private:
		hashNode** mp_hashTable;
		int m_size;
};

}

#endif
