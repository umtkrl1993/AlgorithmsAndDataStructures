
#include <iostream>
using namespace std;
template<typename T>
T adder(T v){
	return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args){
	return first + adder(args...);
}

int main(){

	long sum = adder(1, 3.0, 3, 8, 7);

	std::cout<<sum;


}

 a[i] = a[i-1]*P+Q (modulo 2^31)

 class Box{


 	int length;
 	int breadth;
 	int height;

 public:
 	Box(int len, int breadth, int height){
 		length = len;
 		breadth = breadth;
 		height = height;
 	}

 	Box( Box b ){
 		length = b.length;
 		breadth = b.breadth;
 		height = b.height;
 	}

 	int getLength(){
 		return length;
 	}

 	int getBreadth(){
 		return breadth;
 	}

 	int getHeight(){
 		return height;
 	}

 	long long CalculateVolume() return length*breadth*height;

 	bool operator <( Box b ){
 		if( length < b.length ) return true;

 		else if( ( breadth < b.breadth ) && ( length == b.length ) ) return true;

 		else if( (height < b.height) && (breadth==b.breadth) && (length == b.length)) return true;

 		else return false;
 	}

 	ostream& operator<<(ostream& out, const Box& b){
 		out<< b.length << " " << b.breadth << " " << b.height
 	}

 };