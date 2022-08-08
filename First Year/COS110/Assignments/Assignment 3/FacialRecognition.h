#ifndef FACIALRECOGNITION_H
#define FACIALRECOGNITION_H

#include "ContactlessDevice.h"

class FacialRecognition : public ContactlessDevice {
private:
    int stepSize;

public:
    FacialRecognition(const string &k, const int &max, int stepSize);
    ~FacialRecognition();
    void setStepSize(int step);
    string registerStudent(const string &s);
    string authenticateStudent(const string &s);

protected:
    char hashChar(char);
};

#endif