#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream file("input.txt");
	int num1, num2;
	int size;

	if (file.is_open())
	{
		file >> size;
		for (int i = 0; i < size; i++) {
			file >> num1;
			file >> num2;
			cout << num1 + num2 << " , " << num1 * num2 << endl;
		}
		file.close();
	}
	else cout << "Unable to open file";
	system("pause");
	return 0;

}