#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <exception>

using namespace std;

class weapon {
private:
    int ammo;
    string type;
    string name;
public:
    weapon();
    weapon(int a, string t, string n);

    int getAmmo();
    void setAmmo(int a);

    string getType();
    void setType(string s);

    string getName();
    void setName(string s);

    template <class T>
            void ventWeapon(T heat);

    virtual ~weapon();
    virtual string fire() = 0;

    struct ammoOut : public exception {
        ammoOut();
        virtual ~ammoOut() throw();
        const char * what() const throw();
    };

};

#endif