#include <iostream>
#include <string>

using namespace std;
int main()
{
	//Constants
	const double orwell = 1337.42;
	
	///Variables should be declared here
	string sen = "programming is fun";
	char ch = 'X';
	int first = 75, second = 29;
	bool t = true, f = false;
	
	cout<<ch<<" comes after W in the alphabet"<<endl;
	cout<<"The sum of five and fifteen: "<<first<<endl;
	cout<<"The multiplication of fourteen and a half and two: "<<second<<endl;
	cout<<"Learning "<<sen<<endl;
	cout<<t<<" is the value of True"<<endl;
	cout<<f<<" is the value of False"<<endl;
	cout<<"The constant has a value of "<<orwell<<endl;
	
	int A = 14, B, C, D = 31;
	B = A * D;
	C = D / A;
	A ++;
	D = D - 2;
	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
	cout << D << endl;
	cout << B + C << endl;

	return 0;
}
