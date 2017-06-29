#include "queue.h"
#include "iterator.h"

namespace DataStructures
{

queue::queue( int size ) :
    m_size( size ),
    m_head( 0 ),
    m_tail( 0 )
{
    mp_arr = new int[size];
}

queue::~queue()
{
    delete mp_arr;
}

queue::queue( const queue& copy )
{
    m_size = copy.m_size;
    mp_arr = new int[m_size];
    m_head = copy.m_head;
    m_tail = copy.m_tail;
}

queue& queue::operator=( const queue& copy )
{
    m_size = copy.m_size;
    mp_arr = new int[m_size];
    m_head = copy.m_head;
    m_tail = copy.m_tail;
}

queue::iterator queue::begin()
{
    return queue::iterator( mp_arr, m_size );
}

queue::iterator queue::end()
{
    return queue::iterator( mp_arr, m_size );
}

bool queue::enqueue( int element )
{
   if( ( m_head != 0 ) && ( m_head == m_tail) )
   {
        return false;
   }

    mp_arr[m_tail] = element;
    m_tail = ( m_tail + 1 ) % m_size;

    return true;
}

int queue::dequeue()
{
    int element = mp_arr[m_head];
    
    m_head = ( m_head + 1 ) % m_size;

    return element;
} 

}






