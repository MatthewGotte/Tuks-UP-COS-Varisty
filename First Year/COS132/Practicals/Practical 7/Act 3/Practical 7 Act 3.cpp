#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;

string bubSort(double arr[8]);
string DeleteZeros(string input);

int main()
{
	double arr[8] = {0,0,0,0,0,0,0,0};
	ifstream tfile;
	string sline;
	int pos;
	
	char buffer;
	
	tfile.open("list.txt");
	//tfile >> sline;
	
	//Loop Input
	while (getline(tfile, sline))
	{
		//Clear array values
		for (int i = 0; i < 8; i++)
		{
			arr[i] = 0;
		}
		////////////////////////////
		
		//Read into array ----> arr[8]
		for (int i = 0; i < 8; i++)
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
		
		//Call bubSort and Output
		cout << bubSort(arr) << endl;
	}
	
	tfile.close();
	return 0;
}

string bubSort(double arr[8])
{
	string output, temp;
	int elements = 0;
	
	bool flag = true;
	double swap;
	
	for (int i = 0; i < 8; i++)
	{
		if (arr[i] != 0)
			elements++;
		else
			break;
	}
	
	while (flag)
	{
		flag = false;
		for (int i = 0; i < elements - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = swap;
				flag = true;
			}
		}
	}
	
	//Generate output ----> for into output string;
	for (int i = 0; i < elements; i++)
	{
		if (i < elements - 1)
		{
			ostringstream oss;
			oss.precision(15);
			oss << arr[i];
			output += DeleteZeros(oss.str()) + ",";
		}
		else if (i == elements - 1)
		{
			ostringstream oss;
			oss.precision(15);
			oss << arr[i];
			output += DeleteZeros(oss.str());
		}
		else
			break;
	}
	
	return output;
}

string DeleteZeros(string input)
{
	int pos = -1;
	pos = input.find('e');
	
	if (pos == -1)
	{
		pos = input.find('.');
		for (int i = input.length(); i > pos + 1; i--)
		{
			if (input[i] == '0')
				input.erase(i, i + 1);
		}
	}
	else
	{
		//Output was converted from notation
		string leader, tens;
		leader = input.substr(0, pos);
		pos = -1;
		pos = leader.find(',');
		
		if (pos != -1)
			leader.erase(pos, pos + 1);
		
		pos = input.find('-');
		tens = input.substr(pos + 1, input.length());
		
		int loop;
		istringstream ss(tens);
		ss >> loop;
		input = "0.";
		for (int i = 1; i < loop; i++)
		{
			input += "0";
		}
		input += leader;
	}
	
	return input;
}