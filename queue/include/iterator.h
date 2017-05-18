#include "queue.h"


class queue::iterator
{

public:
    iterator( int* arr );
    void operator++();
    int operator*();

private:
    int current;

};
