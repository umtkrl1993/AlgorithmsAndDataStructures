#include "../include/iterator.h"


queue::iterator::iterator( int* arr )
{
    current = 0;
}

void queue::iterator::operator++()
{
    
}

queue queue::iterator::operator*()
{
    return arr[i];
}

