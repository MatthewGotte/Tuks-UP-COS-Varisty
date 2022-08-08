#include <iostream>
#include "Section.h"
#include "Track.h"
#include "Turn.h"
#include "Straight.h"
#include "Chicane.h"
#include "Observer.h"
#include "FlagObserver.h"
#include "Barrier.h"
#include "PitStop.h"
#include "Decorator.h"
#include "StartLine.h"
#include "GravelTrap.h"

using namespace std;

int main()
{
    //Creating Track
    Track * track = new Track();

    //Creating Sections
    Section ** sections = new Section*[4];
    sections[0] = new Straight();
    sections[1] = new Turn(0); //right turn
    sections[2] = new Turn(180); //left turn
    sections[3] = new Chicane();

    //creating decorations
    Section ** decorations = new Section*[4];
    decorations[0] = new Barrier();
    decorations[1] = new GravelTrap();
    decorations[2] = new PitStop();
    decorations[3] = new StartLine();

    string section_names[4] = {"Straight", "Right Turn", "Left Turn", "Chicane"};
    int option = 1;
    while (option == 1) {

        cout << "\nSection Type: \n1. Straight\n2. Right Turn\n3. Left Turn\n4. Chicane\nchoice > ";
        int type;
        cin >> type;
        type--;

        cout << "\nAdd Decoration to " << section_names[type] << "? 0 => No, 1 => yes > ";
        int decoration;
        cin >> decoration;

        int dec_type;
        bool dec_flag = false;
        if (decoration == 1) {
            cout << "\nDecoration Type: \n1. Barrier\n2. Gravel Trap\n3. Pit Stop\n4. Start Line\nchoice > ";
            cin >> dec_type;
            dec_type--;
            dec_flag = true;
        }

        Section * sec;
        if (type == 0) {
            sec = sections[0];
        } else if(type == 1) {
            sec = sections[1];
        } else if(type == 2) {
            sec = sections[2];
        } else {
            sec = sections[3];
        }
        if (dec_flag) {
            Section * temp;
            if (dec_type == 0) {
                temp = new Barrier();
                temp->add(sec);
            } else if (dec_type == 1) {
                temp = new GravelTrap();
                temp->add(sec);

            } else if (dec_type == 2) {
                temp = new PitStop();
                temp->add(sec);
            } else {
                temp = new StartLine();
                temp->add(sec);
            }
            sec = temp;
        }
        track->add(sec);

        cout << endl << "Add another Section? 0 => No, 1 => yes > ";
        cin >> option;
    }

    //print:
    cout << endl << "------------Printing the track------------" << endl;
    cout << "Section \tAdded Decorations" << endl;
    track->print();

    cout << endl << "-------------Starting a race--------------" << endl;
    FlagObserver* observe = new FlagObserver(track);
    observe->print();
    track->notify();


    cout << endl << "------------------Crash-------------------" << endl;
        track->attach(observe);
        track->setCrash(true);
        track->notify();
        observe->print();


    cout << endl << "---------------Handle Crash---------------" << endl;
        track->setCrash(false);
        track->notify();
        observe->print();
        track->detach(observe);

    cout << endl << "-------------------END-------------------" << endl;

    //cleanup:
    for (int i = 0; i < 4; i++) {
        delete sections[i];
        sections[i] = nullptr;
        delete decorations[i];
        decorations[i] = nullptr;
    }
    delete [] sections;
    delete [] decorations;

    return 0;
}