#include <iostream>
using namespace std;
//int printwater(int w);
int disaster(int w);
char choice;
int main() {
	int water = 3;
	cout << "Dear Player," << endl;
	cout << "If you make water normally, you make a days worth of water. But each day" << endl;
	cout << "the people in the bunker drink 1.5 days worth of water. To avoid death, you" << endl;
	cout << "must occasionaly take risks. If it fails, however, you lose two days worth of water. On the other hand," << endl;
	cout << "if you succeed you'll make two days worth of water. The choice and lives of people's fates are in your hands." << endl;
	cout << "-Sincerely, AMARA" << endl;
	system("pause");
	while (water > 0) {
		cout << "You have " << water << "Days worth of water." << endl;
		system("pause");
		cout << "Right now the workers are making water. Do you want to speed up the water process?" << endl;
			cin >> choice;
			if (choice == 'n') {
				water += 1;
				water -= 1.5;
				cout << "You decided to not take the risk just yet." << endl;
			}
			if (choice == 'y') {
				water += disaster(water);
				water -= 1.5;
			}
			cout << "The day passes by, and now tomorrow is here." << endl;
		

	}
	cout << "Everyone in the bunker died, including you. Tough luck." << endl;
}

void printwater(int w) {

	cout << w << endl;
}
int disaster(int w) {
	cout << "attempting to rush..." << endl;
	system("pause");
	int num = rand() % 50;
	if (num >= 25) {
		cout << "rush successful!" << endl;
		return  5;

	}
	if (num <= 24) {
		cout << "oh no! rush unsuccessful!" << endl;
		return -1;
	}
}