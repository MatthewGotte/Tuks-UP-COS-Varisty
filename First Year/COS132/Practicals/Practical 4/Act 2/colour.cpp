#include <iostream>
#include <string>

using namespace std;

int main()
{

	string colour[6]= {"yellow", "orange", "red", "purple", "blue", "green"};
	string InputColour;
	
	cout << "Input a colour: ";
	getline(cin, InputColour);
	
	int x = -1, y, z;
	
	if (InputColour == "yellow")
	{x = 0;}
	
	 else if (InputColour == "orange")
	{x = 1;}
	
	else if (InputColour == "red")
	{x = 2;}
	
	else if (InputColour == "purple")
	{x = 3;}
	
	else if (InputColour == "blue")
	{x = 4;}
	
	else if (InputColour == "green")
	{x = 5;}
	
	else 
	{
		cout << "Colour not found" << endl;
	}
	
	
	if (x == 0 || x == 2)
	{
		cout << "Input a number: ";
		cin >> y;
		if (y == 1)
			cout << colour[0] << "," << colour[1] << "," << colour[2] << "," << colour[3] << "," << colour[4] << "," << colour[5] << endl;
		else if (y == 2)
			cout << colour[x] << endl;
		else if (y ==3)
			cout << colour[x + 2] << endl;	//Primary Yellow & Red
	}
	else if (x == 4)
	{
		cout << "Input a number: ";
		cin >> y;
		if (y == 1)
			cout << colour[0] << "," << colour[1] << "," << colour[2] << "," << colour[3] << "," << colour[4] << "," << colour[5] << endl;
		else if (y == 2)
			cout << colour[x] << endl;
		else if (y ==3)
			cout << colour[0] << endl;	//Primary Blue
	}
	
	if (x == 1 || x == 3)	 	//Non-Primary Orange & Purple
	{
		cout << "Input a number: ";
		cin >> y;
		if (y == 1)
			cout << colour[0] << "," << colour[1] << "," << colour[2] << "," << colour[3] << "," << colour[4] << "," << colour[5] << endl;
		else if (y == 2)
		{
			//Uppercase InputColour Here
			for (z = 0; z < InputColour.length(); z ++)
			{
				InputColour[z] = toupper(InputColour[z]);
			}
			cout << InputColour << endl;
		}
		else if (y == 3)
			cout << colour[x + 2];
	}
	else if (x == 5)	//Non-Primary Green
	{
		cout << "Input a number: ";
		cin >> y;
		if (y == 1)
			cout << colour[5] << "," << colour[1] << "," << colour[3] << endl;
		else if (y == 2)
		{
			//Uppercase InputColour Here
			for (z = 0; z < InputColour.length(); z ++)
			{
				InputColour[z] = toupper(InputColour[z]);
			}
			cout << InputColour << endl;
		}
		else if (y == 3)
			cout << colour[1] << endl;
	}
	
	
	
	
	return 0;
}