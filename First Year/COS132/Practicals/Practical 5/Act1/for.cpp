#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string pair, snumber;
	int output, number, i;
	char op;
	
	cout << "Enter a pair: ";
	cin >> pair;
	
	if (pair.length() >= 3)
	{
	
		if (pair[1] == ',')
		{
		
			if ((pair[0] == '+') || (pair[0] == '-') || (pair[0] == '*'))
			{
			
				for (i = 2; i <=  pair.length(); i++)
				{
					snumber += pair[i];
				}
				
				number = stoi(snumber);
				
				op = pair[0];
				output = number;
				
				for (i = 0; i < number; i++)
				{
					if (op == '*')
						output *= number;
					else if (op == '+')
						output += number;
					else if (op == '-')
						output -= number;
				}
				
			}
			else output = 0;
			
		}
		else output = 0;
		
	}
	else output = 0;
	
	cout << "Result: " << output << endl;
	
	return 0;
}