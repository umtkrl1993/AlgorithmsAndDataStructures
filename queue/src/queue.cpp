#include "queue.h"
#include "iterator.h"
#include <iostream>

namespace DataStructures
{

queue::queue( int size ) :
    m_maxSize( size ),
    m_head( 0 ),
    m_tail( 0 )
{
    mp_arr = new int[size];
    m_currentSize = 0;
}

queue::~queue()
{
    delete mp_arr;
}

queue::queue( const queue& copy )
{
    m_maxSize = copy.m_maxSize;
    mp_arr = new int[m_maxSize];

    for( int i = 0; i < m_maxSize; i++ )
    {
        mp_arr[i] = copy.mp_arr[i];
    }
    m_head = copy.m_head;
    m_tail = copy.m_tail;
}

queue& queue::operator=( const queue& copy )
{
    m_maxSize = copy.m_maxSize;
    mp_arr = new int[m_maxSize];
    m_head = copy.m_head;
    m_tail = copy.m_tail;
}

queue::iterator queue::begin()
{
    return queue::iterator( (*this), 0 );
}

queue::iterator queue::end()
{
    return queue::iterator( (*this), m_currentSize );
}

bool queue::enqueue( int element )
{
   if( m_maxSize == m_currentSize )
   {
        return false;
   }

    mp_arr[m_tail] = element;
    m_tail = ( m_tail + 1 ) % m_maxSize;
    m_currentSize++;

    return true;
}

int queue::dequeue()
{
    if( m_currentSize == 0 )
    {
        return -1;
    }
    int element = mp_arr[m_head];
    m_head = ( m_head + 1 ) % m_maxSize;
    m_currentSize--;

    return element;
} 

}






