#include<queue.h>
#include<iostream>


int main()
{

	DataStructures::queue que(10);
	que.enqueue( 12 );
	que.enqueue( 20 );


	int re = que.dequeue();
	std::cout<<re<<std::endl;


	return 0;
}
