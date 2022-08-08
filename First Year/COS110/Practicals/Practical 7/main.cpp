#include <iostream>

#include "bin.h"
#include "train.h"
#include "bin.cpp"
#include "train.cpp"
#include <string>

using namespace std;


int main()
{

cout << "Testing Bins" << endl;
cout << "-----1-------" << endl;
cout << "int\n\n";
for(int i = 0; i < 5; i++) { bin<int> s(i *(-10.2)); cout << s.getData() << endl; return 0;}
cout << endl << endl;
cout << "-----2-------" << endl;
cout << "double\n\n";
for(int i = 0; i < 5; i++) { bin<double> s(i *10.2); cout << s.getData() << endl; }
cout << endl << endl;
cout << "-----3-------" << endl;
cout << "char\n\n";
string me = "abcdefghijklmnopqrstuvqxyz";
for(int i = 0; i < 5; i++) { bin<char> s(me[i]); cout << s.getData() << endl; }
cout << "\nNow testing train\n";
cout << "----------4-----------" << endl;
train<char> tr(6);
for(int i = 0; i < 5; i++) { tr.addBin(me[i]);}
tr.printStorage();
cout << "\nCleanUp" << endl;
cout << "----------5-----------" << endl;
for(int i = 0; i < 5; i++) { tr.removeBin(i);}
tr.printStorage();
cout << "\n--------6-------------\n" << endl;
for(int i = 0; i < 7; i++) { tr.addBin(me[i+10]); if(i == 6) cout << tr.addBin(me[i]) << endl;}
cout << "\nShould have a negative 1 above me" << endl;
cout << "\n--------7-------------\n" << endl;
tr.printStorage();
cout << "\n--------8-------------\n" << endl;
cout << "\nClosing\n\n";
cout << "----------9-----------\n" << endl;
train<string> st(4);
string ss[4] = {"142.2", "120", " ", "122"};
st.addBin(ss[0]);
st.addBin(ss[1]);
st.addBin(3,ss[3]);
st.printStorage();

	return 0;
}
/*
Testing Bins
-----1-------
int

0
-10
-20
-30
-40


-----2-------
double

0
10.2
20.4
30.6
40.8


-----3-------
char

a
b
c
d
e

Now testing train
----------4-----------
Bin 1: a
Bin 2: b
Bin 3: c
Bin 4: d
Bin 5: e
Bin 6: NA

CleanUp
----------5-----------
Bin 1: NA
Bin 2: NA
Bin 3: NA
Bin 4: NA
Bin 5: NA
Bin 6: NA

--------6-------------

-1

Should have a negative 1 above me

--------7-------------

Bin 1: k
Bin 2: l
Bin 3: m
Bin 4: n
Bin 5: o
Bin 6: p

--------8-------------


Closing

----------9-----------

Bin 1: 142.2
Bin 2: 120
Bin 3: NA
Bin 4: 122
*/

