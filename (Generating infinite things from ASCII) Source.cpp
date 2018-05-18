#include <iostream>
#include <ctime>
#include<Windows.h>
using namespace std;
int main() {
	
	srand(time(NULL));
	
	//sets up an empty 10-slot character(letters/numbers) array
	char code[10];

	while (1) {

		//put a random number or letter in each slot
		for (int i = 0; i < 10; i++)
			code[i] = rand() % 50 + 48;

		//print out the contents of the array
		cout << code[0] << code[1] << code[2] << code[3] << code[4] << code[5] << code[6] << code[7] << code[8] << code[9] << endl;
	
		Sleep(300);//slows down
		//system("cls");//wipes screen
	
	}

	
	  
	 
	 
	 
	  
	

}