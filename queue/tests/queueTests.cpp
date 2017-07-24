#include "queue.h"
#include "iterator.h"
#include <stdio.h>
using namespace DataStructures;

namespace
{

inline void insertIntoQueue( queue& que )
{
	que.enqueue( 23 );
	que.enqueue( 12 );
	que.enqueue( 21 );
	que.enqueue( 13 );
	que.enqueue( 19 );
	que.enqueue( 49 );
	que.enqueue( 9 );
}

inline void printQueue( const queue& que )
{
	for( queue::iterator it = que.begin(); it != que.end(); (++it) )
	{
		int element = (*it);
		printf( "Element in the queue is %d \n", element );
	}
}

}
int main()
{

queue que( 10 );

insertIntoQueue( que );
printQueue( que );
/**
 * Test for just printing elements
*/
	return 0;

}




