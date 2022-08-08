#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

string linsearch(double arr[], double search[]);

int main()
{

	double arr[10] = {0,0,0,0,0,0,0,0,0,0}, search[8] = {0,0,0,0,0,0,0,0};

	int pos, elements = 1;
	string sline;
	ifstream tfile;
	
	tfile.open("search.txt");
	
	//assign arr array
	tfile >> sline;
	for (int i = 0; i < 10; i++)
	{
		pos = -1;
		pos = sline.find(',');
		if (pos != -1)
		{
			istringstream ss(sline.substr(0, pos));
			ss >> arr[i];
			sline.erase(0, pos + 1);
		}
		else
		{
			istringstream ss(sline);
			ss >> arr[i];
			break;
		}
	}

	//assign search array
	tfile >> sline;
	for (int i = 0; i < 8; i++)
	{
		pos = -1;
		pos = sline.find(',');
		if (pos != -1)
		{
			istringstream ss(sline.substr(0, pos));
			ss >> search[i];
			sline.erase(0, pos + 1);
		}
		else
		{
			istringstream ss(sline);
			ss >> search[i];
			break;
		}
	}
	
	tfile.close();
	cout << linsearch(arr, search);
	return 0;
}


//LIN-SEARCH
string linsearch(double arr[], double search[])
{	
	string output;
	bool found;
	//Outer array ----> search[8]
	for (int i = 0; i < 8; i++)
	{
		if (search[i] != 0)
		{
			//Inner array ----> arr[10]
			found = false;
			for (int z = 0; z < 10; z++)
			{
				if (arr[z] != 0)
				{
					if (arr[z] == search[i])
					{
						found = true;
						output += to_string(z) + "\n";
					}
				}
				else
					break;
			}
			if (found == false)
				output += "NA\n";
		}
		else
			break;
	}
	
	return output;
}