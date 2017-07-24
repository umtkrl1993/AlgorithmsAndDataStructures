#include "iterator.h"

namespace DataStructures
{

queue::iterator::iterator( int* arr, int size, int setIndex )
{
    m_currentIndex = setIndex;
    m_size = size;
    mp_arr = arr;
}

void queue::iterator::operator++()
{
    if( m_currentIndex != m_size )
    {
        m_currentIndex++;
    }    
}

int queue::iterator::operator*()
{
    return mp_arr[m_currentIndex];
}

bool queue::iterator::operator ==( const queue::iterator& it2 )
{
	if( m_size != it2.m_size )
	{
		return false;
	}

	if( m_currentIndex != it2.m_currentIndex )
	{
		return false;
	}

	return true;

}

bool queue::iterator::operator !=( const queue::iterator& it2 )
{
	if( m_currentIndex != it2.m_currentIndex )
	{
		return true;
	}

	return false;
	
}

}
