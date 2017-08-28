#include "queue.h"
#include "iterator.h"
#include <stdio.h>
#include <assert.h>

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

	inline void printQueue( queue& que )
	{
		for( queue::iterator it = que.begin(); it != que.end(); (++it) )
		{
			int element = (*it);
			printf( "Element in the queue is %d \n", element );
		}
	}

	void testCurrentSize()
	{
		queue que( 10 );
		insertIntoQueue(que);
		assert( que.currentSize() == 7 );
		que.dequeue();
		assert( que.currentSize() == 6 );
		que.enqueue( 12 );
		assert( que.currentSize() == 7 );
	}

	void testMaxSize()
	{
		queue que( 10 );
		assert( que.size() == 10  );
	}

	void testDequeue()
	{
		queue que( 10 );

		assert( que.dequeue() == -1 );
		que.enqueue( 2 );
		que.enqueue( 20 );
		que.enqueue( 30 );

		assert( que.dequeue() == 2 );
	}


}
int main()
{

	queue que( 10 );
	insertIntoQueue( que );
	printQueue( que );
	testCurrentSize();
	testMaxSize();
	testDequeue();
/**
 * Test for just printing elements
*/
	return 0;
}




