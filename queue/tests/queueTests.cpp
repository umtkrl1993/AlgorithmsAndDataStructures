#include "queue.h"
#include "iterator.h"
#include <stdio.h>
using namespace DataStructures;
int main()
{

queue que( 10 );
que.enqueue( 23 );
que.enqueue( 12 );
que.enqueue( 21 );
queue::iterator it = que.begin();
int element = (*it);
printf(" First element in que is %d \n ", element );
	
	return 0;

}








