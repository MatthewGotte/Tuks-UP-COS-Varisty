#ifndef TOME_H
#define TOME_H
#include <string>

using namespace std;

class tome {
    string references[5];
    string tomeName;
    string author;
    int currSpells;
public:
    tome(string name, string author);
    tome(string name, int tomeSize, string author, string * initialList);
    ~tome();
    int getTomeSize() const;
    string getSpell(int i) const;
    string getName() const;
    string getAuthor() const;
    friend ostream& operator<<(ostream& output, const tome & t);
    tome operator+(const string &add);
    tome operator-(const string &sub);
    tome &operator=(const tome& oldTome);
    bool operator>(const tome &t);
    bool operator<(const tome &t);
    bool operator==(const tome &t);
};

#endif