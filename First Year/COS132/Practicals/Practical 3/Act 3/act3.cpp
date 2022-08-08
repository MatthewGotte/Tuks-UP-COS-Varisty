#include <iostream>

#include <stdlib.h>

using namespace std;

int main()
{
	int StudentNo, i;
	
	cout << "Enter your student number: ";
	cin >> StudentNo;
	
	if (StudentNo % 2 == 0)
	{
		//Even
		i = rand() % 99 + 10;
		cout << i << " is ready to take on COS 132!" << endl;
	}
	else 
	{
		//Odd
		cout << StudentNo << " is really excited for COS 132!" << endl;
	}
	
	return 0;
}