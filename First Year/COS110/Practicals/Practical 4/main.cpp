#include <iostream>
using namespace std;
#include "tome.h"

int main(){
    cout << "-----------------------Testing First constructor  --------------------------"<< endl;
    cout << "Testing the first contructor "<< endl;
    tome t1("fresh water", "Triumph ndlovu");
    cout << "Tome name : "<< t1.getName()<< endl;
    cout << "Author name : "<< t1.getAuthor()<< endl;
    cout << "---------------------------First constructor  worked --------------------------"<< endl;
    cout << endl;
    cout << endl;
    cout << "---------------------------Testing the second contractor --------------------------"<< endl;
    string refs[4] ={"A","B","K","z"};
    string refs2[4] ={"A","B","K","z"};
    tome t3("dance",4,"Too much",refs2);

    tome t2("Oscar",4,"makwakwa",refs);
    cout << "Tome name : "<< t2.getName()<< endl;
    cout << "Tome Author : "<< t2.getAuthor()<< endl;
    cout << "Tome size: "<< t2.getTomeSize()<< endl;
    cout << "Spell in position 4: "<< t2.getSpell(3)<< endl;
    cout << endl;
    cout << endl;
    cout << "---------------------------print function   --------------------------"<< endl;
    cout << t2 << endl;
    cout << "---------------------------print function  worked  --------------------------"<< endl;
    cout << endl;
    cout << endl;
    cout << "--------------------add overload--------------------------------"<< endl;
    t2 + "Triumph Ndlovu";
    cout << t2 << endl;//something is wrong here
    cout << endl;
    cout << endl;
    cout << "--------------------subtract overload--------------------------------"<< endl;
    t2 - "B";
    cout << t2 << endl;
    cout << endl;
    cout << endl;
    cout << "--------------------subtract overload--------------------------------"<< endl;
    tome t20 = t2;
    cout << t20 << endl;
    cout << endl;
    cout << endl;
    cout << "--------------------> sign-------------------------------"<< endl;
    if(t3 > t2)
        cout << "its greter than" << endl;
    else cout << "less than "<< endl;
    cout << endl;
    cout << endl;
    cout << "--------------------< sign-------------------------------"<< endl;
    if(t3 < t2)
        cout << "its less than" << endl;
    else cout << "greter than "<< endl;
    cout << endl;
    cout << endl;
    cout << "--------------------== sign-------------------------------"<< endl;
    if(t2 == t3){
        cout << "They are the same "<< endl;
    }else
    {
        cout << "They are not the same "<< endl;
    }

    return 0;

}