#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
	string sname, sline;
	ifstream tfile;
	int current, previous = 0, stop = -1;

	cout << "Enter the file name: ";
	getline(cin, sname);

	tfile.open(sname);

	if (tfile)
	{
		while (getline(tfile, sline))
		{
			stop = sline.find("stop");
			if (stop == -1)
			{
				current = stoi(sline);
				cout << current + previous << endl;
				previous = current;
			}
			else
			{
				cout << "File reading stopped\n";
				break;
			}
		}
	}

	tfile.close();	
	return 0;
}
