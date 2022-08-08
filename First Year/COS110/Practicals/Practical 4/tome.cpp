#include <iostream>
#include <string>

#include "tome.h"

using namespace std;

tome::tome(string name, string author)
{
    this->tomeName = name;
    this->author = author;
    for (int i = 0; i < 5; i++) {
        references[i] = "";
    }
    currSpells = 0;
}

tome::tome(string name, int tomeSize, string author, string * initialList)
{
    this->tomeName = name;
    this->author = author;
    this->currSpells = tomeSize;
    for (int i = 0; i < 5; i++)
        references[i] = "";
    for (int i = 0; i < tomeSize; i++) {
        references[i] = initialList[i];
    }
}

tome::~tome()
{

}

int tome::getTomeSize() const {
    return currSpells;
}

string tome::getSpell(int i) const {
    return references[i];
}

string tome::getName() const {
    return tomeName;
}

string tome::getAuthor() const {
    return author;
}

bool tome::operator==(const tome &t) {
    bool f1 = false, f2 = true;

    if (this->currSpells == t.currSpells)
        f1 = true;

    int x, y;

    for (int i = 0; i < 5; i++) {
        string temp = this->references[i];
        x = 0;
        y = 0;
        for (int i = 0; i < 5; i++) {
            if (this->references[i] == temp)
                x++;
            if (t.references[i] == temp)
                y++;
        }
        if (x != y) {
            f2 = false;
            break;
        }
    }

    if (f1 && f2)
        return true;
    return false;
}

tome & tome::operator=(const tome &oldTome) {
    this->author = oldTome.author;
    this->currSpells = oldTome.currSpells;
    this->tomeName = oldTome.tomeName;
    for (int i = 0; i < 5; i++) {
        this->references[i] = oldTome.references[i];
    }
    return *this;
}

bool tome::operator>(const tome &t) {
    if (this->currSpells > t.currSpells)
        return true;
    return false;
}

bool tome::operator<(const tome &t) {
    if (this->currSpells < t.currSpells)
        return true;
    return false;
}

tome tome::operator-(const string &sub) {
    for (int i = 0; i < 5; i++) {
        if (this->references[i] == sub) {
            this->references[i] = "";
            this->currSpells--;
            break;
        }
    }
    return *this;
}

tome tome::operator+(const string &add) {
    if (currSpells != 5) {
        for (int i = 0; i < 5; i++) {
            if (this->references[i] == "") {
                this->references[i] = add;
                this->currSpells++;
                break;
            }
        }
    }
    return *this;
}

ostream& operator<<(ostream& output, const tome & t) {
   output << "Tome Name: " << t.tomeName << endl;
   output << "Author: " << t.author << endl;
   output << "References: ";
   for (int i = 0; i < 5; i++) {
        if (t.references[i] != "") {
            if (i != 0) {
                output << ", ";
            }
            output << t.references[i];
        }
   }
   output << endl;
   return output;
}