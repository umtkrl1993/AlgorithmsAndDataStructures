#ifndef _QUEUE_H
#define _QUEUE_H

class queue
{
public:
    queue( int size );
    ~queue();
    queue( const queue* copy );
    queue& operator=( const queue& copy );
    bool enqueue( int element );
    int dequeue( int element );

private:
    int head;
    int tail;
    int* array; 

};



#endif
