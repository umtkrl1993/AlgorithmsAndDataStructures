#include<iostream>

class Graph{

	public:

		Graph( int vertex_number ){

			this->m_vertex_number = vertex_number;
			initializeGraph();
		}

		~Graph(){



		}

		void addEdge( int src, int dst ){

			graphVertex* src_vertex = mp_graph[src];

			graphVertex* current = src_vertex->next;
			graphVertex* pre = current;

			while( current != nullptr ){

				pre = current;
				current = current->next;
			}

			graphVertex* new_vertex = new graphVertex;

			new_vertex->next = nullptr;
			new_vertex->dest = dst;

			if( pre == nullptr ){

				src_vertex->next = new_vertex;
					
			}
			else{
				pre->next = new_vertex;
			}

		}
		
		void addVertex(){

			m_vertex_number++;
			expandMemory();		

			
		}

		void printGraph(){

			for( int i = 0; i < m_vertex_number; i++ ){

				graphVertex* current = mp_graph[i]->next;

				while( current != nullptr ){
					std::cout << "Edge From " << i << " To " << current->dest << std::endl;
					current = current->next;
				}

				std::cout << "-------------------------------------------------" << std::endl;

			}

		}



	private:
		void initializeGraph(){
			
			mp_graph = new struct graphVertex*[m_vertex_number];

			for( int i = 0; i < m_vertex_number; i++ ){
				mp_graph[i] = new struct graphVertex;
				mp_graph[i] -> dest = i;
			}
		}

		void expandMemory(){

			graphVertex** temp = nullptr;

			for( int i = 0; i < m_vertex_number; i++ ){



			}

		}

		typedef struct graphVertex{

			struct graphVertex* next;

			graphVertex(){

				next = nullptr;
			}

			/**
			graphVertex& operator=( const graphVertex& copy_vertex ){

				this->next = nullptr;
				this->dest = copy_vertex.dest;

				return *this;
			}	
			*/
				
			int dest;

		}graphVertex;

		int m_vertex_number;

		graphVertex** mp_graph;

};



int main(){

	Graph g( 10 );

	g.addEdge( 0 , 3 );
	g.addEdge( 0, 4 );
	g.addEdge( 0, 5 );
	g.addEdge( 0, 6 );
	g.addEdge( 1, 2 );
	g.addEdge( 2, 4 );
	g.addEdge( 3, 9 );
	g.addEdge( 4, 8 );
	g.addEdge( 4, 6 );
//g.addEdge( 5, 7 );


	g.printGraph();
	
	

	return 0;
}
