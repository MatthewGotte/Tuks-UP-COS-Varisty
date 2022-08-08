#include <iostream>

#include <iomanip>
#include <string>

using namespace std;
int main()
{
	string name;
	char c = '*';
	
	cout << "Please enter you name: ";
	getline(cin, name);
	
	cout << "Welcome: " << setfill(c) << setw(8) << name << endl;
	
	return 0;
}