#include "queue.h"

namespace DataStructures
{
class queue::iterator
{

public:
    iterator( queue& que ,int setIndex );
    void operator++();
    int operator*();
	bool operator ==( const iterator& it2 );
	bool operator !=( const iterator& it2 );

private:
    int m_currentIndex;
	queue m_parent;

};
}
