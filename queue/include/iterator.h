#include "queue.h"

namespace DataStructures
{
class queue::iterator
{

public:
    iterator( int* arr, int size );
    void operator++();
    int operator*();

private:
    int m_currentIndex;
    int m_size;
    int* mp_arr;

};
}
