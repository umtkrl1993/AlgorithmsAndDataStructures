
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct AttrMap{

	string name;
	string value;

};



class TagMap{

public:
	string tag_name;
	vector<AttrMap*> attrs;
};


void parse_line( string& line, int index, TagMap* tags ){


	if( line[1] == '/'){
		return;
	}


	int i = 0;

	bool cont = true;

	int index_first_space = line.find(' ');
	string tag_name = line.substr(1, index_first_space-1);

	line = line.substr( index_first_space+1 );

	tags[index].tag_name = tag_name;


	// start consuming attributes for the tag
	while( cont ){

		index_first_space = line.find(' ');
		string attr_name = line.substr(0, index_first_space);
		line = line.substr(index_first_space+3);
		string attr_value;
		index_first_space = line.find(' ');
		if( index_first_space == -1 ){ 
			int index_greater = line.find('>');
			attr_value = line.substr(0,index_greater);
			cont = false;
		}
		else{
			attr_value = line.substr(0, index_first_space);
			line = line.substr(index_first_space+1);
		}

		AttrMap* attr = new AttrMap;
		attr->name = attr_name;
		attr->value = attr_value;

		tags[index].attrs.push_back( attr );

	}

}

string get_attr_value(const string& tag_name, const string& attr_name, const TagMap* tags, int tag_size ){

	TagMap target ;
	bool found = false;
	string attr_value = "";
	for( int i = 0; i < tag_size; i++ ){
		if( tags[i].tag_name == tag_name ){
			target = tags[i];
			found = true;
			break;
		}
	}

	if( found == false )
		return "Not Found!";

	vector<AttrMap*> attrs = target.attrs;
	found = false;
	for( vector<AttrMap*>::iterator it = attrs.begin(); it != attrs.end(); it++ ){
		if( (*it)->name == attr_name ){
			attr_value = (*it)->value;
			found = true;
			break;
		}
	}

	if( found == false ){
		return "Not Found!";
	}

	return attr_value;


}
void find_attr_value( string& line, const TagMap* tags, int tag_size, queue<string>& output_queue ){

	int last_index_dot = line.find_last_of('.');
	int index_tilda = line.find('~');
	string tag_name;
	string attr_name;


	if( last_index_dot != -1 ){
		tag_name = line.substr(last_index_dot+1, index_tilda-last_index_dot-1);
		attr_name = line.substr(index_tilda+1);
	}
	else{
		tag_name = line.substr(0, index_tilda);
		attr_name = line.substr(index_tilda+1);
	}

	string attr_value = get_attr_value( tag_name, attr_name, tags, tag_size );

	//cout<<"tag name "<<tag_name<<endl;
	//cout<<"attr name "<<attr_name<<endl;

	output_queue.push( attr_value );

}


int main(){

	int N;
	int Q;
	TagMap* tags;
	cin>>N;
	cin>>Q;
	tags = new TagMap[N/2];
	string line;
	cin.ignore();
	queue<string> output_queue;

	for( int i = 0; i < N; i++ ){
		getline(cin,line);
		parse_line( line, i, tags );
	}


	
	for( int i = 0; i < Q; i++ ){
		getline(cin,line);
		find_attr_value( line, tags, N/2, output_queue );
	}

	int out_size = output_queue.size();
	for( int i = 0; i < out_size; i++ ){
		string str = output_queue.front();
		str.erase(remove(str.begin(), str.end(), '"'), str.end());
		cout<<str<<endl;
		output_queue.pop();
	}

	/**
	cout<<tags[0].tag_name<<endl;
	cout<<tags[0].attrs[0]->name<<endl;
	cout<<tags[0].attrs[0]->value<<endl;
	cout<<tags[1].tag_name<<endl;
	*/


	return 0;
}