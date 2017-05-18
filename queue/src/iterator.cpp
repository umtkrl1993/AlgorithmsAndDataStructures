#include "../include/iterator.h"


queue::iterator::iterator( int* arr, int size )
{
    m_currentIndex = 0;
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

