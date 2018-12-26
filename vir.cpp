#include <iostream>
#include <string>

using namespace std;

class Person{

public:
	Person(){

	}
	Person(string& p_name, int p_age)
	: name(p_name)
	{
		age = p_age;
	}
	virtual void getdata(){

		cin>>name;
		cin>>age;

	}

	virtual void putdata(){
		cout<<name<<" "<<age;
	}

private:
	string name;
	int age;

};

class Professor : public Person{

public:
	Professor(){
		cur_id = ++Professor::obj_id;

	}
	Professor(string& name, int p_age, int p_publications)
		:Person(name, p_age)
	{
		publications = p_publications;
		cur_id = Professor::obj_id;
		Professor::obj_id++;
	}

	void getdata(){
		Person::getdata();
		cin>>publications;

	}

	void putdata(){
		Person::putdata();
		cout<<" "<<publications<<" "<<cur_id<<endl;
	}

private:
	static int obj_id;
	int publications;
	int cur_id;

};

int Professor::obj_id = 0;


class Student:public Person{

public:
	Student(){
		cur_id = ++Student::obj_id;
	}
	void getdata(){

		Person::getdata();
		int tmp = 0;
		for( int i = 0; i < 6; i++ ){
			cin>>tmp;
			marks[i] = tmp;
		}

	}

	void putdata(){
		Person::putdata();
		cout<<" ";
		int sum = 0;
		for( int i = 0; i<6; i++ ){
			sum+=marks[i];
		}
		cout<<sum<<" "<<cur_id<<endl;
	}
private:
	int marks[6];
	static int obj_id;
	int cur_id;


};

int Student::obj_id = 0;