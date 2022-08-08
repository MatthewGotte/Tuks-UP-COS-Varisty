#include <iostream>

using namespace std;

#include "MerchandiseFactory.h"
#include "Merchandise.h"
#include "ArsenalFactory.h"
#include "LiverpoolFactory.h"
#include "ChelseaFactory.h"

void resize(int howmuch);

int size = 0;
Merchandise** merch = new Merchandise*[size];

int main() {
    //creating the factories:
    int type, club, quantity, iSize, iInflated;
    bool bInflated;
    string sSize;
    MerchandiseFactory ** factory = new MerchandiseFactory*[3];
    factory[0] = new LiverpoolFactory;
    factory[1] = new ChelseaFactory;
    factory[2] = new ArsenalFactory;
    bool flag = true;
    while (flag) {
        cout << "Type of Merchindise:" << endl;
        cout << "\t1. Soccer Ball" << endl;
        cout << "\t2. Shirt" << endl;
        cout << "\tSelection: ";
        cin >> type;
        if (type != 1 && type != 2) {
            cout << "Invalid Selection!" << endl;
            return 0;
        }

        cout << "Club:" << endl;
        cout << "\t1. Liverpool" << endl;
        cout << "\t2. Chelsea" << endl;
        cout << "\t3. Arsenal" << endl;
        cout << "\tSelection: ";
        cin >> club;
        if (club != 1 && club != 2 && club != 3) {
            cout << "Invalid Selection!" << endl;
            return 0;
        }

        switch (type) {
            case 1: {
                cout << "Should the ball(s) be inflated? > " << endl;
                cout << "\t1. Inflated" << endl;
                cout << "\t2. Deflated" << endl;
                cout << "\tSelection: ";
                cin >> iInflated;
                if (iInflated == 1)
                    bInflated = true;
                else if (iInflated == 2)
                    bInflated = false;
                else {
                    cout << "Invalid selection!" << endl;
                    return 0;
                }
                break;
            }
            case 2: {
                cout << "Size: " << endl;
                cout << "\t1. Small" << endl;
                cout << "\t2. Medium" << endl;
                cout << "\t3. Large" << endl;
                cout << "\tSelection: ";
                cin >> iSize;
                if (iSize == 1)
                    sSize = "Small";
                else if (iSize == 2)
                    sSize = "Medium";
                else if (iSize == 3)
                    sSize = "Large";
                else {
                    cout  << "Invalid selection!" << endl;
                    return 0;
                }
                break;
            }
        }

        cout << "How many merchandise items should be created? > ";
        cin >> quantity;
        if (quantity <= 0) {
            cout << "Invalid Selection!" << endl;
            return 0;
        }

        int last = size;
        resize(quantity);
        for (int i = 0; i < quantity; i++) {
            switch (type) {
                case 1: {
                    //soccerball
                    switch (club) {
                        case 1: {
                            //liverpool ball
                            merch[last++] = factory[0]->CreateSoccerBall(bInflated);
                            cout << " - " << merch[last - 1]->getDescription() << endl;
                            break;
                        }
                        case 2: {
                            //chelsea shirt
                            merch[last++] = factory[1]->CreateSoccerBall(bInflated);
                            cout << " - " << merch[last - 1]->getDescription() << endl;
                            break;
                        }
                        case 3: {
                            //arsenal shirt
                            merch[last++] = factory[2]->CreateSoccerBall(bInflated);
                            cout << " - " << merch[last - 1]->getDescription() << endl;
                            break;
                        }
                    }
                    break;
                }
                case 2: {
                    //shirt
                    switch (club) {
                        case 1: {
                            //liverpool shirt
                            merch[last++] = factory[0]->CreateShirt(sSize);
                            cout << " - " << merch[last - 1]->getDescription() << endl;
                            break;
                        }
                        case 2: {
                            //chelsea shirt
                            merch[last++] = factory[1]->CreateShirt(sSize);
                            cout << " - " << merch[last - 1]->getDescription() << endl;
                            break;
                        }
                        case 3: {
                            //arsenal shirt
                            merch[last++] = factory[2]->CreateShirt(sSize);
                            cout << " - " << merch[last - 1]->getDescription() << endl;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        cout << endl << "Enter 1 to create more items or 0 to stop > ";
        int rep;
        cin >> rep;
        if (rep != 1)
            flag = false;
    }
    //clean up:
    for (int i = 0; i < 3; i++) {
        delete factory[i];
    }
    delete [] factory;
    factory = nullptr;
    for (int i = 0; i < size; i++) {
        delete merch[i];
    }
    delete [] merch;
    merch = nullptr;
	return 0;
}

void resize(int howmuch) {
    Merchandise** temp = new Merchandise*[size + howmuch];
    for (int i = 0; i < size; i++) {
        temp[i] = merch[i];
    }
    merch = temp;
    size += howmuch;
}