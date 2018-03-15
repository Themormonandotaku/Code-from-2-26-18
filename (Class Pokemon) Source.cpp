#include <iostream>
using namespace std;
char foodDrop(char location);
//class definition!
class pokemon {
	public:
		void eat(char food);
		void gameover();
		void initpok();
		void printinfor();
		
	private:
		int health;

};

int main() {
	pokemon gung;
	pokemon gliggle;

	gung.initpok();
	gliggle.initpok();
	while (1) {
		gung.printinfor();
		gung.eat(foodDrop('d'));
		gung.printinfor();
		system("pause");
	}


}//main

void pokemon::initpok() {
	health = 5;

}

void pokemon::printinfor() {
	cout << "your pokemon's health is now " << health << endl;

}

void pokemon::eat(char food) {

	if (food == 'b')
		health += 3;
	if (food == 'm')
		health += 2;
	if (food == 'c')
		health += 1;
	if (food == 'f')
		health += 2;
	if (food == 'a')
		health -= 1;
	if (food == 't')
		health -= 3;
}

void pokemon::gameover() {
	if (health == 0)
		cout << "Your pokemon dies. Game over." << endl;

}

char foodDrop(char location) {

	int num = rand() % 100 + 1;

	if (location == 'f') {
		if (num <= 50) {
			cout << "you got a berry!" << endl;
			return 'b';
		}
		else {
			cout << "you got a mushroom!" << endl;
			return 'm';

		}
	}
	else if (location == 'd') {
		if (num <= 20) {
			cout << "You got a berry!" << endl;
			return 'b';
		}
		else if (num <= 60) {
			cout << "You got a fruit!" << endl;
			return 'f';
		}
		else if (num < 100) {
			cout << "You found some cheese?" << endl;
			return 'c';
		}
	}


	else
		cout << "invalid location" << endl;

}