#include "FacialRecognition.h"
#include "ContactlessDevice.h"

#include <iostream>
#include <sstream>

using namespace std;

FacialRecognition::FacialRecognition(const string &k, const int &max, int stepSize) {
    this->setKeyword(k);
    this->maxStudent = max;
    this->stepSize = stepSize;
    this->currentStudent = 0;
    this->studentDatabase = new string*[max];
    for (int i = 0; i < max; i++) {
        this->studentDatabase[i] = new string[2];
        this->studentDatabase[i][0] = "z";
        this->studentDatabase[i][1] = "z";
    }
    this->rotor = nullptr;
}

FacialRecognition::~FacialRecognition() {
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

void FacialRecognition::setStepSize(int step) {
    string e = "Negative number provided";
    if (step < 0) {throw Exception(e);}
    this->stepSize = step;
}

string FacialRecognition::registerStudent(const string &s) {
    //Save Rotor & keyword:
    int * tempKey = new int[length];
    for (int i = 0; i < length; i++) {tempKey[i] = this->keyword[i];}

    std::string out = ContactlessDevice::registerStudent(s);

    //Restore rotor & keyword:
    for (int i = 0; i < length; i++) {
        this->keyword[i] = tempKey[i];
    }
    this->setRotor();
    delete tempKey;

    return out;
}

string FacialRecognition::authenticateStudent(const string &s) {
    //Save Rotor & keyword:
    int * tempKey = new int[length];
    for (int i = 0; i < length; i++) {tempKey[i] = this->keyword[i];}

    std::string out = ContactlessDevice::authenticateStudent(s);

    //Restore rotor & keyword:
    for (int i = 0; i < length; i++) {
        this->keyword[i] = tempKey[i];
    }
    this->setRotor();
    delete tempKey;

    return out;
}

char FacialRecognition::hashChar(char c) {
    /*cout << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < length; j++) {
            cout << this->rotor[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;*/

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

    //Rotate Table:
    for (int i = 0; i < 10; i++) {
        //store:

        this->rotor[i][0] += this->stepSize;
        if (this->rotor[i][0] >= 10) {this->rotor[i][0] -= 10;}

        for (int j = 1; j < length; j++) {
            this->rotor[i][j] = this->keyword[j] + this->rotor[i][j - 1];
            if (this->rotor[i][j] >= 10) {this->rotor[i][j] -= 10;}
        }
    }

    //Store new key:
    for (int i = 0; i < length; i++) {
        this->keyword[i] = this->rotor[0][i];
    }
    return out;
}