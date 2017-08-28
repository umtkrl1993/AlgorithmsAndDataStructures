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
	int size() const { return m_maxSize; }
	int currentSize() const { return m_currentSize; }
    class iterator;
    iterator begin();
    iterator end();

private:
    int m_head;
    int m_tail;
    int* mp_arr;
	int m_currentSize;
    int m_maxSize;
};

}

#endif
