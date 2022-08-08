#include "PalmVein.h"
#include "ContactlessDevice.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

PalmVein::PalmVein(const string &s, const int &maxStud) {
    this->studentDatabase = nullptr;
    this->rotor = nullptr;

    string e = "The keyword provided is not going to generate a safe encryption";
    if (s.length() <= 1) { throw Exception(e); }

    this->studentDatabase = new string *[maxStud];
    for (int i = 0; i < maxStud; i++) {
        this->studentDatabase[i] = new string[2];
        this->studentDatabase[i][0] = "z";
        this->studentDatabase[i][1] = "z";
    }
    this->currentStudent = 0;
    this->maxStudent = maxStud;
    this->setKeyword(s);
}

PalmVein::~PalmVein() {
    //Keyword:
    delete [] this->keyword;

    //**rotor:
    if (this->rotor != nullptr) {
        for (int i = 0; i < 10; i++) {
            delete this->rotor[i];
        }
        delete [] this->rotor;
    }

    //studentDatabase:
    if (this->studentDatabase != nullptr) {
        for (int i = 0; i < this->maxStudent; i++) {
            delete [] this->studentDatabase[i];
        }
        delete [] this->studentDatabase;
    }
}

/*string PalmVein::registerStudent(const string &) {
 *
}
make
string PalmVein::authenticateStudent(const string &) {

}*/

char PalmVein::hashChar(char c) {
    int temp;
    stringstream ss;
    ss << c;
    ss >> temp;
    int out;
    for (int i = 0; i < 10; i++) {
        if (this->rotor[i][length - 1] == temp) {
            out = i;
        }
    }
    return out;
}

