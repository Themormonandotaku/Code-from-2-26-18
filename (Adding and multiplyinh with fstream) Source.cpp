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
//In the 'input' file, the first line is how many numbers the program will use, which is the added sum and the
//multiplied sum. The other two lines/ the numbers following that line is the numbers that the program will be
//using. No spaces, just one number at the start of each line
