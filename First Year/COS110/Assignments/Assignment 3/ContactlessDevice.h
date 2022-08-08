#ifndef CONTACTLESSDEVICE_H
#define CONTACTLESSDEVICE_H

#include "AccessDevice.h"
#include <string>


class ContactlessDevice : public AccessDevice {

protected:
    int length = 0;
    int * keyword;
    int maxStudent;
    int currentStudent;
    int ** rotor;
    string ** studentDatabase;

public:
    string registerStudent(const string& s);
    string authenticateStudent(const string& s);
    int * setKeyword(const string& s);
    void setRotor();
    int ** getRotor();
    string ** getStudentDatabase();

protected:
    virtual char hashChar(char) = 0;


};

#endif