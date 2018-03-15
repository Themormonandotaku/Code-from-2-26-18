#include <iostream>
#include <string>
using namespace std;

string a;
string b;
string c;
void monogram();
int main() {
	cout << "Type in a first, middle, and last name." << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	monogram();
}
void monogram() {
	cout << a << c << b;
	
}