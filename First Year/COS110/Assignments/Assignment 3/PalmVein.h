#ifndef PALMVEIN_H
#define PALMVEIN_H

#include "ContactlessDevice.h"

#include <string>

using namespace std;

class PalmVein : public ContactlessDevice {
public:
    PalmVein(const string& s, const int& maxStud);
    ~PalmVein();
    //string registerStudent(const string&);
    //string authenticateStudent(const string&);

protected:
    char hashChar(char c);
};

#endif