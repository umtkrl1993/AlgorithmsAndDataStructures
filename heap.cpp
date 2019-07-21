
#include<cstddef>
#include<stdexcept>
#include<iostream>

using namespace std;


template<class T>
void insertion_sort( T arr[], int size ){

	for( int i = 1; i < size; i++ ){


		int key = i;
		int j = i - 1;

		while( arr[key] < arr[j] && j > -1 ){

			arr[j+1] = arr[j];
			j--; 
		}

		arr[j+1] = arr[key];
	}

}


template<class T>
void insertion_sort_alter( T arr[], int size ){

	T arr_index[size];


}
class duplicate_key{

public:
	virtual void debug_print() const { std::cerr<<"duplicate key"<<std::endl;}

};

template<class K, class V>
class Heap;


template<class K, class V>
class HeapEntry{
public:

	HeapEntry(){

	}
	HeapEntry( K k, V v ):
		key(k), value(v)
		{

		}

	HeapEntry(const HeapEntry<K,V>& e2){
		key = e2.key;
		value = e2.value;
	}

	void operator =(const HeapEntry<K,V>& e2){
		key = e2.key;
		value = e2.value;
	}

	bool operator >( const HeapEntry<K,V>& e2 ){
		return (key>e2.key) ? true : false;
	}

	template<class U, class C>
	friend ostream& operator<<( ostream& out, const HeapEntry<U,C>& entry );

	friend class Heap<K,V>;

private:
	K key;
	V value;


};

template<class K, class V>
ostream& operator<<( ostream& out, const HeapEntry<K,V>& entry ){

	out<<"key " << entry.key << " " <<"value "<<entry.value<<endl;
	return out;

}

template <class K, class V> 
class Heap{

public:
	Heap(std::size_t capasity = 20){
		m_capasity = capasity;
		m_size = 0;
		mp_heap_arr = new HeapEntry<K,V>[capasity];
	}

	Heap(const Heap& h2);


	~Heap(){
		delete [] mp_heap_arr;
	}

	void insert( K key, V value );

	HeapEntry<K,V> extract_min();

	void downheap( int index );


	

	void printHeap() const{

		for( int i = 0; i < m_size; i++ ){
			cout<<mp_heap_arr[i];
		}
	}

	bool operator <(const Heap<K,V>& h){
		return true;
	}


	void heapify( int index );

private:
	HeapEntry<K,V>* mp_heap_arr;
	std::size_t m_capasity;
	std::size_t m_size;

	

	void swap(int index, int parent){
		HeapEntry<K,V> temp = mp_heap_arr[index];
		mp_heap_arr[index] = mp_heap_arr[parent];
		mp_heap_arr[parent] = temp;
	}	

	int getParent( int index ) const{
		return index/2;
	}




};

template<class K, class V>
Heap<K,V>::Heap(const Heap<K,V>& h2){



}

template<class K, class V>
void Heap<K, V>::insert(K key, V value){

	if( m_size == m_capasity ){
			throw std::out_of_range("capasity is full");
	}
		m_size = m_size+1;
		mp_heap_arr[m_size].key = key;
		mp_heap_arr[m_size].value = value;
	///	std::cout<<"key is "<<key<<std::endl;
	//	std::cout<<"in insert" << mp_heap_arr[m_size].key<<std::endl;
		heapify(m_size);
		
		
}

template<class K, class V>
void Heap<K,V>::heapify( int index ){
		int parent = getParent(index);
		while( index > 0 && mp_heap_arr[index].key < mp_heap_arr[parent].key ){

			swap( index, parent );
			index = parent;
			parent = getParent(index);

		}
}

template<class K, class V>
void Heap<K,V>::downheap( int index ){

	if( index >= m_size ) return;
	K min = mp_heap_arr[index].key;
	int min_index = index;
	if( ( 2*index <= m_size ) && min > mp_heap_arr[2*index].key ){
		min = mp_heap_arr[2*index].key;
		min_index = 2*index;
	}

	if( ( 2*index+1 <= m_size ) && min > mp_heap_arr[2*index+1].key ){ 
		min = mp_heap_arr[2*index+1].key;
		min_index = 2*index+1;
	}

	if( min_index != index ){ 
		swap( min_index, index );
		downheap(min_index);
	}


}

template<class K, class V>
HeapEntry<K,V> Heap<K,V>::extract_min(){

	HeapEntry<K,V> min_element = mp_heap_arr[1];

	mp_heap_arr[1] = mp_heap_arr[m_size];

	m_size--;

	downheap(1);

	return min_element;

}


int main(int argc, char* argv[] ){


	Heap<int, int> heap(20);
	heap.insert(2,5);
	heap.insert(3,4);
	heap.insert(5,2);
	heap.insert(1,2);

//	heap.printHeap();

	
	Heap<int, string> job_scheduler;

	//const HeapEntry<int,int> entry = heap.extract_min();
	//cout<<entry;

//	 cout<<heap.extract_min();


	
	 int time;
	 string name;

	 while( 1 ){
	 	cin>>time;
	 	cin>>name;

	 	if( time == -1 )
	 		break;

	 	job_scheduler.insert( time, name );

	}


	for( int i = 0 ; i < 2; i++ ){
		cout<<job_scheduler.extract_min();
	}

	
	//heap.printHeap();

	//std::map<Dummy, int> mp;

	//mp.insert(std::pair<Dummy,int>(Dummy(),2));
}