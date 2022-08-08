#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using namespace std;

class Exception {
protected:
    string error;
public:
    Exception(string& error);
    string getError();
};

#endif