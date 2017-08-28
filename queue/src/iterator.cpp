#include "iterator.h"

namespace DataStructures
{

queue::iterator::iterator( queue& que, int setIndex )
: m_parent( que )
{
    m_currentIndex = setIndex;
}

// Should return iterator object in case of it = it++;
void queue::iterator::operator++()
{
    if( m_currentIndex != m_parent.m_size )
    {
        m_currentIndex++;
    }    
}

int queue::iterator::operator*()
{
    return m_parent.mp_arr[m_currentIndex];
}

// Do NOT use sizes to compare iterators use data comparision
bool queue::iterator::operator ==( const queue::iterator& it2 )
{

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
