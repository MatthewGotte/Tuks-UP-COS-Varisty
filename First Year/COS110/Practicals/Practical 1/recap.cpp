#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	int rows = 0 , longest = 2, cols;
	ifstream tfile;
	tfile.open("data.txt");
	string sline;
	
	while (getline(tfile, sline))
	{
		rows++;
		cols = 1;
		for (int i = 0; i < sline.length(); i++)
			if (sline[i] == ',')
				cols++;
		if (cols > longest)
			longest = cols;
	}
	cols = longest;
	
	string ** ary = new string*[rows];
	for (int i = 0; i < rows; i++)
	{
		ary[i] = new string[cols];
	}
	
	tfile.clear();
	tfile.seekg(tfile.beg);
	
	for (int i = 0; i < rows; i++)
	{
		getline(tfile, sline);
		for (int z = 0; z < cols; z++)
		{
			int pos = -1;
			pos = sline.find(',');
			if (pos != -1)
			{
				ary[i][z] = sline.substr(0, pos);
				sline.erase(0, pos + 1);
			}
			else
			{
				ary[i][z] = sline;
				break;
			}
		}
	}
	
	string * swap = new string[cols];
	int n1, n2;
	stringstream ss;
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < rows - 1; i++)
		{
			stringstream ss;
			ss << ary[i][0];
			ss >> n1;
			ss.clear();
			ss << ary[i + 1][0];
			ss >> n2;
			if (n1 > n2)
			{
				for (int p = 0; p < cols; p++)
					swap[p] = ary[i][p];
				for (int p = 0; p < cols; p++)
					ary[i][p] = ary[i + 1][p];
				for (int p = 0; p < cols; p++)
					ary[i + 1][p] = swap[p];
				flag = true;
			}
			ss.clear();
		}
	}
	delete [] swap;
	
	//==========================
	string output;
	for (int i = 0; i < rows; i++)
	{
		output.clear();
		int items = 0;
		for (int p = 0; p < cols; p++)
			if (ary[i][p] != "\0")
				items++;
		for (int j = 0;  j < cols; j++)
		{
			output += ary[i][j];
			if (items > 1)
				output += ",";
			items--;
		}
		cout << output << endl;
	}
	
	//Deallocation of Memory
	tfile.close();
	for (int i = 0; i < rows; i++)
	{
		delete [] ary[i];
	}
	delete [] ary;
	
	return 0;
}