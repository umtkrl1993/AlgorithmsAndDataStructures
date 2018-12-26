
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};


class LRUCache:public Cache{

public:

	LRUCache(int cap){
		cp = cap;
		head = NULL;
		tail = NULL;
	}

	virtual void set( int key, int value ){

		bool is_present = false;
		map<int,Node*> :: iterator it = mp.find(key);

		if( it != mp.end() ){
			is_present = true;
		}



		if( mp.size() == cp ){

			Node* new_key = new Node( key, value );

			if( is_present == false ){

				//remove least used node
				Node* last_node = tail;
				Node* pre_last = last_node->prev;
				pre_last->next = NULL;
				tail = pre_last;
				mp.erase( last_node->key);
				delete last_node;

				//add new key to the head
				Node* first_node = head;
				new_key->prev = NULL;
				new_key->next = first_node;
				first_node->prev = new_key;
				head = new_key;
			}

			else{

				map<int, Node*>::iterator it = mp.find(key);
				Node* current = it->second;
				current->prev->next = current->next;
				current->next->next = current->prev;
				head->prev = current;
				current->next = head;
				head = current;
			}
			mp.insert( pair<int,Node*>( key, new_key ) );

		}
		else{
			

			if( is_present == false ){ 

				Node* new_key = new Node( key, value );

				if( head == NULL ){
					new_key->next = NULL;
					new_key->prev = NULL;
					head = new_key;
					tail = new_key;
				}
				else{ 
					
					new_key->next = head;
					new_key->prev = NULL;
					head->prev = new_key;
					head = new_key;
				}

				mp.insert( pair<int,Node*>( key, new_key ) );

			}
			else{

				Node* new_key = new Node( key, value );
				map<int, Node*>::iterator it = mp.find(key);

				Node* current = it->second;

				current->prev->next = current->next;
				current->next->prev = current->prev;

				current->next = head;
				current->next->prev = current;
				head = current;

				current->value = value;

				mp.erase(key);

				mp.insert( pair<int, Node*>( key, new_key ) );



			}

		}

	}

	virtual int get(int key){

		bool is_present = false;
		map<int,Node*>::iterator it = mp.find(key);

		if( it != mp.end() ){
			return it->second->value;
		}

		return -1;
	}

};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
