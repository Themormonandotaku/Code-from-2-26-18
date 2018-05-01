#include <iostream>
using namespace std;
void copy(int& a, int& b, int& c)//This will multiply the values of x, y, and z by 2 (Unless you change the numbers)
{
	a *= 2;
	b *= 2;
	c *= 2;
}
int main()
{
	int x = 1, y = 3, z = 7;
	copy(x, y, z);
	cout << "x =" << x << ", y =" << y << ", z =" << z;
	return 0;
}