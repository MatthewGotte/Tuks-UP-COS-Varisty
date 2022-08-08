#include <iostream>

#include "laser.h"
#include "weapon.h"
#include "missile.h"
#include "fireControl.h"

using namespace std;

int main() {
    laser x(5);
    x.setName("Big laser");
    cout << x.getName() << endl;

    cout << "\n1--------------------\n" << endl;

    cout << x.getStrength() << endl;
    x.setStrength(10);
    cout << x.getStrength() << endl;

    cout << "\n2--------------------\n" << endl;

    x.setAmmo(5050);
    cout << x.getAmmo() << endl;

    cout << "\n3--------------------\n" << endl;

    double test = 52.2;
    x.ventWeapon(59);

    cout << "\n4--------------------\n" << endl;

    x.setAmmo(10);
    cout << x.getAmmo() << endl;
    cout << x.getStrength() << endl;
    try {
        cout << x.fire() << endl;
    }
    catch (weapon::ammoOut e) {
        cout << e.what() << endl;
    }
    cout << x.getStrength() << endl;
    cout << x.getAmmo() << endl;

    cout << "\n5--------------------\n" << endl;

    x.setAmmo(0);

    try {
        cout << x.fire() << endl;
    } catch (weapon::ammoOut e) {
        cout << e.what() << endl;
    }

    cout << "\n6--------------------\n" << endl;

    missile p;

    cout << "\n7--------------------\n" << endl;

    p.setName("Big missile");
    cout << p.getName() << endl;

    cout << "\n8--------------------\n" << endl;

    p.setAmmo(10);
    cout << p.getAmmo() << endl;
    cout << p.fire() << endl;
    cout << p.getAmmo() << endl;

    cout << "\n9--------------------\n" << endl;

    p.ventWeapon(2);
    cout << endl;
    p.ventWeapon(29);

    cout << "\n10--------------------\n" << endl;

    cout << p.getAmmo() << endl;
    try {
        cout << p.fire() << endl;
    } catch (weapon::ammoOut e) {
        cout << e.what() << endl;
    }
    cout << p.getAmmo() << endl;

    cout << "\n11--------------------\n" << endl;

    string * arr = new string[4];
    arr[0] = "LasER";
    arr[1] = "bigger LaseR";
    arr[2] = "normal MissiLe";
    arr[3] = "SMALL miSSILE";
    fireControl frCtrl(4, arr);

    cout << "\n12--------------------\n" << endl;

    cout << frCtrl.accessWeapon(2)->getName() << endl;

    cout << "\n13--------------------\n" << endl;

    try {
        cout << frCtrl.accessWeapon(10)->getName() << endl;
    } catch (fireControl::weaponFailure e) {
        cout << e.what() << endl;
    }

    cout << "\n14--------------------\n" << endl;

    return 0;
}

/*
 Output:

Big laser

1--------------------

5
10

2--------------------

5050

3--------------------

Heat Cycle 1
Heat Cycle 2
Heat Cycle 3
Heat Cycle 4
Heat Cycle 5

4--------------------

10
10
Big laser fired at strength: 10
11
9

5--------------------

Ammo Depleted!

6--------------------


7--------------------

Big missile

8--------------------

10
Big missile fired!
9

9--------------------

Insufficient heat to vent

Heat Cycle 1
Heat Cycle 2

10--------------------

9
Big missile fired!
8

11--------------------


12--------------------

normal MissiLe

13--------------------

Weapon System Failure!

14--------------------

LasER Uninstalled!
bigger LaseR Uninstalled!
normal MissiLe Uninstalled!
SMALL miSSILE Uninstalled!
Big missile Uninstalled!
Big laser Uninstalled!

 */