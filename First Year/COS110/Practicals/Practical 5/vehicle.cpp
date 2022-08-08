#include "vehicle.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

vehicle::vehicle() {

}

void vehicle::setName(string s) {
    this->name = s;
}

string vehicle::getName() {
    return name;
}

char ** vehicle::getMap() {
    return map;
}

int vehicle::getSize() {
    return size;
}

void vehicle::setMap(string s) {
    ifstream tfile;
    tfile.open(s);

    string sline;
    int lines;

    getline(tfile, sline);
    stringstream ss;
    ss << sline;
    ss >> lines;

    size = lines;

    map = new char*[lines];
    for (int i = 0; i < lines; i++) {
        map[i] = new char[lines];

    }

    for (int i = 0; i < lines; i++) {
        getline(tfile, sline);
        for (int j = 0; j < lines; j++) {
            map[i][j] = sline[j];
        }
    }

    /*cout << endl;
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;*/


}

char vehicle::getMapAt(int x, int y) {
    return map[x][y];
}

vehicle::~vehicle() {

}

void vehicle::operator--() {
    for (int i = 0; i < size; i++) {
        delete map[i];
        map[i] = nullptr;
    }
    delete [] map;
}

void vehicle::determineRouteStatistics() {

}