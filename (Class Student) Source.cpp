#include <iostream>
using namespace std;
#include<string>
class student {
public:
	void init(int a, int i, char g, string l);
	void print();
private:
	int age;
	int id;
	char gender;
	string lastname;
	string firstname;
	

	//classes about students. ironic
};

int main() {
	student roy;
	student celica;
	student cain;
	student hinoka;
	
	//the vaiables of the students
	roy.init(16, 580255, 'm', "whatever");
	celica.init(16, 580596, 'f', "ferloin");
	cain.init(16, 580145, 'm', "benstillin");
	hinoka.init(16, 580423, 'f', "janeson");

	roy.print();
	celica.print();
	cain.print();
	hinoka.print();

	system("pause");
}
void student::init(int a, int i, char g, string l) {
	age = a;
	id = i;
	gender = g;
	lastname = l;
}
void student::print() {
	cout << "age is " << age << " , id is " << id << " , gender is " << gender << " , lastname is "<< lastname << endl;
}