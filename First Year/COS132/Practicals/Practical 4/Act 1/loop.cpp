#include <iostream>

using namespace std;

int main()
{
	int iCounter = 0, iInt;
	
	cout << "Enter an int: ";
	cin >> iInt;
	
	while (iInt >= 0)
	{
		if (iInt % 2 != 0)
		{
			iCounter++;
		}
		iInt --;
	}
	
	cout << "Number of Odds: " << iCounter << endl;
	
	return 0;
}