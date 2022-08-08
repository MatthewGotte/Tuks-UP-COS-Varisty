#include "ContactlessDevice.h"

#include <string>
#include <sstream>
#include <iostream>
#include "Exception.h"

using namespace std;

string ContactlessDevice::registerStudent(const string& s) {
    string e = "Student Database is full";
    if (this->maxStudent == this->currentStudent) {throw Exception(e);}

    string out = "";
    this->studentDatabase[currentStudent][0] = s;
    for (int i = 0; i < s.length(); i++) {
        out += to_string(hashChar(s[i]));
    }

    e = "Student already exist";
    for (int i = 0; i < this->maxStudent; i++) {
        if (this->studentDatabase[i][0] == s && this->studentDatabase[i][1] == out) {
            throw Exception(e);
        }
    }

    studentDatabase[currentStudent][1] = out;
    this->currentStudent++;

    return out;
}

string  ContactlessDevice::authenticateStudent(const string& s) {
    string out = "";
    for (int i = 0; i < s.length(); i++) {
        out += to_string(hashChar(s[i]));
    }
    string flag = "false";
    for (int i = 0; i < this->maxStudent; i++) {
        if (this->studentDatabase[i][0] == s && this->studentDatabase[i][1] == out) {
            flag = "true";
        }
    }
    return out + flag;
}

int * ContactlessDevice::setKeyword(const string& s) {
    string e1 = "Invalid input";
    string e2 = "The keyword provided is not going to generate a safe encryption";

    length = s.length();
    for (int i = 0; i < length; i++) {
        if (!isdigit(s[i])) {
            if (s[i] == ' ') {
                throw Exception(e2);
            }
            else
                throw Exception(e1);
        }
    }
    if (s.length() <= 1) {throw Exception(e2);}


    this->keyword = new int[length];
    for (int i = 0; i < length; i++) {
        stringstream ss;
        ss << s[i];
        ss >> this->keyword[i];
        ss.clear();
    }

    return this->keyword;
}

int ** ContactlessDevice::getRotor() {
    return this->rotor;
}

void ContactlessDevice::setRotor() {
    string e = "Keyword must be set";
    if (keyword == nullptr) {
        throw Exception(e);
    }

    //Set Rotor:
    rotor = new int*[10];
    for (int i = 0; i < 10; i++) {
        rotor[i] = new int[length];
    }

    int counter = 0;
    for (int i = keyword[0]; i < keyword[0] + 10; i++) {
        rotor[counter][0] = i;
        if (rotor[counter][0] >= 10) {rotor[counter][0] -= 10;}
        counter++;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < length; j++) {
            rotor[i][j] = keyword[j] + rotor[i][j - 1];
            if (rotor[i][j] >= 10) {rotor[i][j] -= 10;}
        }
    }
}

string ** ContactlessDevice::getStudentDatabase() {
    return this->studentDatabase;
}

//hashChar() = 0;

Exception::Exception(string &error) {
    this->error = error;
}

string Exception::getError() {
    return this->error;
}