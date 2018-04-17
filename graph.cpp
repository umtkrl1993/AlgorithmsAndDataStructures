#include <iostream>
#include <map>
#include <string>
#include <queue>

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


		void bfs( int start ){
			int discovered[m_vertice_number] = {0};
			std::queue< graphVertex* > bfs_que;

			graphVertex* current = mp_graph[start]->next;


			while( current != nullptr ){

				bfs_que.push( current );
				current = current->next;
			}

			//bfs_que.push( current );

			discovered[start] = 1;

			while( !bfs_que.empty() ){

				graphVertex* current = bfs_que.front();
				discovered[current->dest] = 1;
				std::cout << "from" << m_id_map_to_vertice[start] << "to" << m_id_map_to_vertice[current->dest] << std::endl;
				bfs_que.pop();

				//get adjacent vertice
				current = mp_graph[current->dest]->next;

				//add adjacent nodes of current to queue
				while( current != nullptr ){
					bfs_que.push( current );
					current = current->next;

				}

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



};



int main(){

	Graph g( 10 );

	g.addVertex( "Ankara" );
	g.addVertex( "Istanbul" );
	g.addVertex( "Izmir" );
	g.addVertex( "Adana" );
	g.addVertex( "Antalya");
	g.addVertex( "Erzurum");
	g.addVertex( "Sivas");

	g.addEdge( "Ankara", "Istanbul", 500 );
	g.addEdge( "Ankara", "Izmir", 800 );
	g.addEdge( "Ankara", "Adana", 400 );
	g.addEdge( "Izmir", "Istanbul", 450 );
	g.addEdge( "Izmir", "Antalya", 250 );
	g.addEdge( "Istanbul", "Antalya", 600);
	g.addEdge( "Istanbul", "Erzurum", 880 );

	g.bfs( 1 );






	g.printGraph();
	
	

	return 0;
}
