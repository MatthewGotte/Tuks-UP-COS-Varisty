#ifndef ACCESSDEVICE_H
#define ACCESSDEVICE_H

#include "Exception.h"

#include <string>

using namespace std;

class AccessDevice {
public:
    virtual string registerStudent(const string& s) = 0;
    virtual string authenticateStudent(const string& s) = 0;
};

#endif