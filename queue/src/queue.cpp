#include "queue.h"


queue::queue( int size ) :
    m_size( size )
{
    arr = new int[size];
}

queue::~queue()
{
    delete arr;
}

queue::queue( const queue& copy )
{

}







