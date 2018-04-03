#include <iostream>
#include <map>
#include <string>

class Graph{

	public:

		Graph( int vertex_number ){

			this->m_vertex_number = vertex_number;
			this->m_vertice_index = 0;
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
		
		void addVertex( std::string vertice_name ){

			std::map< std::string , int >::iterator it = m_vertice_map.find( vertice_name );

			if( it == m_vertice_map.end() ){
				m_vertice_map[vertice_name] = m_vertice_index++;
			}
			else{
				m_vertice_map.erase( it );
			}

		}

		void printGraph(){

			for( int i = 0; i < m_vertex_number; i++ ){

				graphVertex* current = mp_graph[i]->next;

				while( current != nullptr ){
					std::cout << "Edge From " << i << " To " << current->dest << std::endl;
					current = current->next;
				}

			}

		}

		void printVertices(){

			for( std::map< std::string, int >:: iterator it = m_vertice_map.begin(); it != m_vertice_map.end(); it++ ){
				std::cout << it->first << '\n';
			}

		}

		void printNeigh( int node ){

			graphVertex* current = mp_graph[node]->next;

			while( current != nullptr ){
		
					std::cout << current->dest << '\n';
					current = current->next;

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
		std::map< std::string, int > m_vertice_map;
		int m_vertice_index;

};



int main(){

	Graph g( 10 );

	g.addVertex( "Ankara" );
	g.addVertex( "Istanbul" );
	g.addVertex( "Izmir" );
	g.addVertex( "Adana" );
	g.addVertex( "Antalya");

	g.printVertices();


//
//	g.addEdge( 0 , 3 );
//	g.addEdge( 0, 4 );
//	g.addEdge( 0, 5 );
//	g.addEdge( 0, 6 );
//	g.addEdge( 1, 2 );
//	g.addEdge( 2, 4 );
//	g.addEdge( 3, 9 );
//	g.addEdge( 4, 8 );
//	g.addEdge( 4, 6 );
//	g.addEdge( 6, 0);
//	g.addEdge( 6,1);
//	g.addEdge( 6,5);
//	g.addEdge( 6,6);

	g.printNeigh( 6 );
//g.addEdge( 5, 7 );


	//g.printGraph();
	
	

	return 0;
}
