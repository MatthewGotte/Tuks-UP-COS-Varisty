#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	
	string sline, tab = "\t";
	int arr[4][4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	ifstream tfile;
	int num1, num2, num3, num4;
	char c;
	int totalsum = 0;
	
	tfile.open("values.txt");
	
	if (tfile)
	{
		for (int w = 0; w < 4; w++)
		{
			tfile >> sline;
			stringstream CSV(sline);
			CSV >> num1 >> c >> num2 >> c >> num3 >> c >> num4;
			arr[w][0] = num1;
			arr[w][1] = num2;
			arr[w][2] = num3;
			arr[w][3] = num4;
		}
	}
	
	//SUM ROWS//////////////////////////////////////////////////////////////////////////////////////
	
	int temp;
	
	for (int p = 0; p < 4; p++)
	{
		temp = 0;
		for (int i = 0; i < 4; i++)
		{
			temp += arr[p][i];
		}
		cout << "Row Total " << p + 1 << ": " << temp << endl;
		totalsum += temp;
	}
	
	//SUM COLUMNS///////////////////////////////////////////////////////////////////////////////
	
	for (int p = 0; p < 4; p++)
	{
		temp = 0;
		for (int i = 0; i < 4; i++)
		{
			temp += arr[i][p];
		}
		cout << "Col Total " << p + 1 << ": " << temp << endl;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	cout << "Array Average: " << totalsum / 16 << endl;
	
	/*cout << "\n" << "----ARRAY OUTPUT----\n" << endl;
	
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			cout << arr[x][y] << tab;
		}
		cout << endl;
	}*/
	
	tfile.close();
	
	return 0;
}