#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
	ifstream tfile;
	string sline, num1, num2, num3;
	int i;
	int bins[3] = {0,0,0};
	
	
	tfile.open("values.txt");
	
	if (tfile)
	{
		while (getline(tfile,sline))
		{

			i = sline.find(',');
			num1 = sline.substr(0, i);
			bins [0] += stoi(num1);
			
			sline.erase(0, i + 1);
			i = sline.find(',');
			num2 = sline.substr(0, i);
			bins [1] += stoi(num2);
			
			sline.erase(0, i + 1);
			num3 = sline.substr(0, sline.length());
			bins[2] += stoi(num3);
			
		}
		
	}
	cout << bins[0] << endl << bins[1] << endl << bins[2] << endl;
	return 0;
}