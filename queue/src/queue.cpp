#include "../include/queue.h"

namespace DataStructures
{

queue::queue( int size ) :
    m_size( size ),
    m_head( 0 ),
    m_tail( 0 );
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

}

iterator queue::begin()
{
    return iterator( mp_arr, int m_size );
}

iterator queue::end()
{

}

bool queue::enqueue( int element )
{
   if( ( m_head != 0 ) && ( m_head == m_tail) )
   {
        printf( "Queue is currently full\n" );  
        return false;
   }

    mp_arr[m_tail] = element;
    m_tail = ( m_tail + 1 ) % m_size;

    return true;
}

int queue::dequeue()
{

} 

}






