#include <iostream>
using namespace std;
int main()
{
	float myPi;
	float * piPointer;
	///User Input
	cout<<"Enter a float number: ";
	cin>>myPi;
	piPointer = &myPi;
	cout << myPi << endl;
	myPi = myPi + 10.3;
	cout << myPi << endl;

	return 0;
}