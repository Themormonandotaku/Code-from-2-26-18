#include <iostream>
using namespace std;
//The fibonacci sequence is when you add the previous number to the current number.
//Example: 1 + 1 = 2. 2 + 1 = 3. 2 + 3 = 5. 5 + 3 = 8. 8 + 5 = 13.
//If you change the while, it'll go on infinitely.
int main() {
	int help1 = 0; int help2 = 1; int help3 = 1;
	cout << help1 << " " << help2 << " ";
	while (help3 = help1 < 9)
	{
		help3 = help1 + help2;
		help1 = help2;
		help2 = help3;
		cout << help3 << " ";


	}
	cout << endl;
	return 0;
}