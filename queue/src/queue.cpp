#include "../include/queue.h"

queue::queue( int size ) :
    m_size( size )
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

}

queue







