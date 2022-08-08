#include <iostream>
#include <iomanip>

#include <math.h>

using namespace std;
int main()
{
	float x, y;
	cout << "Enter a value of x: ";
	cin >> x;
	y =  (cos(pow(x, 3)) / (18 + (2 * M_PI)))  +  ((sin(pow(x, 2))) / (19 + (3 * M_PI)))  +  (tan(x) / (20 + (4 * M_PI)));
	cout << "The answer is: " << fixed << setprecision(7) << y << endl;
	
	return 0;
}