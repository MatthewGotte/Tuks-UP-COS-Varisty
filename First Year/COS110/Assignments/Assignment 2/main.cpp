#include "matrix.h"
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

    ifstream tfile;
    tfile.open("input.txt");
    Matrix x(3,3);
    tfile >> x;
    cout << x << endl;
    tfile.close();
    tfile.clear();
    tfile.open("inputb.txt");
    Matrix y(3,1);
    tfile >> y;
    cout << y << endl;

    double * temp = x|y;
    Matrix Solutions = x|=y;
    cout << Solutions << endl;

    return 0;
}
/* Output
0         0
0         0

0
0

12        3
2        -3

15
13
 */