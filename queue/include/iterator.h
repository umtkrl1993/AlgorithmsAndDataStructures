#include "queue.h"

namespace DataStructures
{
class queue::iterator
{

public:
    iterator( int* arr, int size, int setIndex );
    void operator++();
    int operator*();
	bool operator ==( const iterator& it2 );
	bool operator !=( const iterator& it2 );

private:
    int m_currentIndex;
    int m_size;
    int* mp_arr;

};
}
