#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

string echo1(string);
string echo2(string, int);

int main()
{
	ifstream tfile;
	string sline;
	int i = 0;
	
	tfile.open("values.txt");
	if (tfile)
	{
		while(getline(tfile, sline))
		{
			cout << echo1(sline) << endl;
			cout << echo2(sline, i) << endl;
			i++;
		}
	}
	return 0;
}

string echo1(string in)
{
	return in;
}

string echo2(string in, int num)
{
	if (num % 2 == 0)
		return in + to_string(num);
	else
		return to_string(num) + in;
}