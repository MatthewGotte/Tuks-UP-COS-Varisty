#ifndef FIRECONTROL_H
#define FIRECONTROL_H

#include "weapon.h"
#include "laser.h"
#include <exception>

class fireControl {
private:
    weapon ** weapons;
    int numWeapons;
public:

    fireControl(int numWeapons, string * weaponList);
    ~fireControl();
    weapon * accessWeapon(int i);

    //Exception Classes:
    struct weaponFailure : public exception {
        weaponFailure();
        virtual  ~weaponFailure() throw();
        const char * what() const throw();
    };

};

#endif