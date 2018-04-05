#include <iostream>
#include <map>
#include <string>

class Graph{

	public:

		Graph( int vertex_number ){

			this->m_vertice_number = vertex_number;
			this->m_vertice_index = 0;
			initializeGraph();
		}

		~Graph(){



		}


		//undirected graph
		void addEdge( std::string src, std::string dst, int weight ){

			int src_id = m_vertice_map_to_id[src];
			int dst_id = m_vertice_map_to_id[dst];

			graphVertex* src_vertex = mp_graph[src_id];

			graphVertex* current = src_vertex->next;
			graphVertex* pre = current;

			while( current != nullptr ){

				pre = current;
				current = current->next;
			}

			graphVertex* new_vertex = new graphVertex;
			new_vertex->weight = weight;
			new_vertex->next = nullptr;
			new_vertex->dest = dst_id;

			if( pre == nullptr ){
				src_vertex->next = new_vertex;
			}

			else{
				pre->next = new_vertex;
			}

		}
		
		void addVertex( std::string vertice_name ){

			std::map< std::string , int >::iterator it = m_vertice_map_to_id.find( vertice_name );

			if( it == m_vertice_map_to_id.end() ){
				m_id_map_to_vertice[m_vertice_index] = vertice_name;
				m_vertice_map_to_id[vertice_name] = m_vertice_index++;
			}
			else{
				m_vertice_map_to_id.erase( it );
			}

		}

		void printGraph(){


			for( int i = 0; i < m_vertice_number; i++ ){

				graphVertex* current = mp_graph[i]->next;

				while( current != nullptr ){
					std::cout << "Edge From " << m_id_map_to_vertice[i] << " To " << m_id_map_to_vertice[current-> dest] << " Distance is " << current->weight << std::endl;
					current = current->next;
				}

			}

		}

		void printVertices(){

			for( std::map< std::string, int >:: iterator it = m_vertice_map_to_id.begin(); it != m_vertice_map_to_id.end(); it++ ){
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

		int m_vertice_number;

		typedef struct graphVertex{

			struct graphVertex* next;
			int weight;
			int dest;

			graphVertex(){
				next = nullptr;
				weight = 0;
			}

		}graphVertex;


		graphVertex** mp_graph;
		std::map< std::string, int > m_vertice_map_to_id;
		std::map< int, std::string > m_id_map_to_vertice;
		int m_vertice_index;

		void initializeGraph(){
			
			mp_graph = new graphVertex*[m_vertice_number];

			for( int i = 0; i < m_vertice_number; i++ ){
				mp_graph[i] = new graphVertex;
				mp_graph[i] -> dest = i;
			}
		}

		void expandMemory(){

			graphVertex** temp = nullptr;

			for( int i = 0; i < m_vertice_number; i++ ){



			}

		}


};



int main(){

	Graph g( 10 );

	g.addVertex( "Ankara" );
	g.addVertex( "Istanbul" );
	g.addVertex( "Izmir" );
	g.addVertex( "Adana" );
	g.addVertex( "Antalya");

	g.addEdge( "Ankara", "Istanbul", 500 );
	g.addEdge( "Ankara", "Izmir", 800 );
	g.addEdge( "Ankara", "Adana", 400 );
	g.addEdge( "Izmir", "Istanbul", 450 );
	g.addEdge( "Izmir", "Antalya", 250 );
	g.addEdge( "Istanbul", "Antalya", 600);






	g.printGraph();
	
	

	return 0;
}
