#ifndef _QUEUE_H
#define _QUEUE_H

namespace DataStructures
{

class queue
{
public:
    queue( int size );
    ~queue();
    queue( const queue& copy );
    queue& operator=( const queue& copy );
    bool enqueue( int element );
    int dequeue();
    class iterator;

private:
    int m_head;
    int m_tail;
    int* mp_array; 
    int m_size;
};

}

#endif
