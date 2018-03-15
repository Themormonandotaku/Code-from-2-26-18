#include <iostream>
#include <string>
using namespace std;
string input;
int main() {
	string slot[3];
	bool hastaco = false;
	cout << "Put in some of your favorite foods." << endl;
	for (int a = 0; a < 3; a++) {
		cin >> input;
		slot[a] = input;
	}
	for (int a = 0; a < 3; a++) {
		if (slot[a] == "taco" || slot[a] == "tacos")
			hastaco = true;

	}
	if (hastaco == true)
		cout << "You have a taco." << endl;
	else
		cout << "You do not have a taco." << endl;
	system("pause");
		




}