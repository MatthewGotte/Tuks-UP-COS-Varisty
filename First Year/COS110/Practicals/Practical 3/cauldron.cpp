#include "cauldron.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

cauldron::cauldron(string ingredientList,int cmaxIngredients)
{
    ifstream tfile;
    string sline;
    tfile.open(ingredientList);

    maxIngredients = cmaxIngredients;
    numIngredients = 0;

    ingredients = new ingredient*[maxIngredients];
    for (int i = 0; i < maxIngredients; i++)
        ingredients[i] = nullptr;

    string temp;
    int z;

        for (int i = 0; i < maxIngredients; i++) {
            sline = "";
            getline(tfile, sline);
            if (sline.length() != 0) {
                int pos = sline.find(',');
                temp = sline.substr(0, pos);
                sline.erase(0, pos + 1);
                stringstream ss;
                ss << sline;
                ss >> z;
                ss.clear();
                ingredients[i] = new ingredient(temp, z);
                numIngredients++;
            }
            sline.clear();
        }
}

cauldron::cauldron(const cauldron* oldCauldron)
{
    numIngredients = oldCauldron->numIngredients;
    maxIngredients = oldCauldron->maxIngredients;
    ingredients = new ingredient*[maxIngredients];

    for (int i = 0; i < maxIngredients; i++)
        ingredients[i] = nullptr;

    for (int i = 0; i < maxIngredients; i++)
    {
        if (oldCauldron->getIngredient(i) != nullptr)
        {
            ingredients[i] = new ingredient(oldCauldron->getIngredient(i));
        }
    }
}

void cauldron::operator=(const cauldron& oldCauldron)
{
    for (int i = 0; i < this->maxIngredients; i++) {
        if (this->ingredients[i] != nullptr) {
            delete this->ingredients[i];
            this->ingredients[i] = nullptr;
        }
    }

    this->numIngredients = oldCauldron.numIngredients;
    this->maxIngredients = oldCauldron.maxIngredients;
    int max = oldCauldron.maxIngredients;
    int num = oldCauldron.numIngredients;

    delete [] this->ingredients;
    this->ingredients = nullptr;
    this->ingredients = new ingredient*[max];
    for (int i = 0; i < max; i++) {
        if (oldCauldron.ingredients[i] != nullptr) {
            this->ingredients[i] = new ingredient(oldCauldron.ingredients[i]);
        } else {
            this->ingredients[i] = nullptr;
        }
    }
}

cauldron::~cauldron()
{
    for (int i = 0; i < maxIngredients; i++)
    {
        if (ingredients[i] != nullptr)
        {
            delete ingredients[i];
            ingredients[i] = nullptr;
        }
    }
    delete [] ingredients;
}

void cauldron::print()
{
    if (numIngredients != 0) {
        cout << "Number of Ingredients: " << numIngredients << endl;
        int a = 0;
        for (int i = 0; i < maxIngredients; i++) {
            if (ingredients[i] != nullptr)
                a += ingredients[i]->getDanger();
        }
        cout << "Average Danger Rating: " << a / numIngredients << endl;

        int h, l;
        for (int i = 0; i < maxIngredients; i++) {
            if (ingredients[i] != nullptr) {
                h = ingredients[i]->getDanger();
                l = ingredients[i]->getDanger();
                break;
            }
        }
        for (int i = 0; i < maxIngredients; i++) {
            if (ingredients[i] != nullptr) {
                if (ingredients[i]->getDanger() > h)
                    h = ingredients[i]->getDanger();
                if (ingredients[i]->getDanger() < l)
                    l = ingredients[i]->getDanger();
            }
        }
        cout << "Maximum Danger Rating: " << h << endl;
        cout << "Minimum Danger Rating: " << l << endl;
    }
}

int cauldron::getMax() const
{
    return maxIngredients;
}

int cauldron::getCurr() const
{
    return numIngredients;
}

ingredient* cauldron::getIngredient(int a) const
{
    return ingredients[a];
}

int cauldron::addIngredient(string in,int dR)
{
    if (!(numIngredients < maxIngredients))
    {
        //Full
        //Copy:
        ingredient ** temp;
        temp = new ingredient*[maxIngredients];

        for (int i = 0; i < maxIngredients; i++)
            temp[i] = nullptr;

        for (int i = 0; i < maxIngredients; i++)
        {
            if (ingredients[i] != nullptr)
            {
                temp[i] = new ingredient(ingredients[i]);
            }
        }

        //Deallocate old:
        for (int i = 0; i < maxIngredients; i++)
        {
            if (ingredients[i] != nullptr)
            {
                delete ingredients[i];
                ingredients[i] = nullptr;
            }
        }
        delete [] ingredients;
        ingredients = nullptr;

        maxIngredients++;

        ingredients = new ingredient*[maxIngredients];
        for (int i = 0; i < maxIngredients; i++)
            ingredients[i] = nullptr;

        for (int i = 0; i < maxIngredients - 1; i++)
        {
            if (temp[i] != nullptr)
            {
                ingredients[i] = new ingredient(temp[i]);
            }
        }

        ingredients[maxIngredients - 1] = new ingredient(in, dR);

        //delete temp
        for (int i = 0; i < maxIngredients - 1; i++)
        {
            if (temp[i] != nullptr)
            {
                delete temp[i];
                temp[i] = nullptr;
            }
        }
        delete [] temp;
        temp = nullptr;
        numIngredients++;
        return maxIngredients - 1;
    }
    else
    {
        //Add
        for (int i = 0; i < maxIngredients; i++)
        {
            if (ingredients[i] != nullptr)
            {
                ingredients[i] = new ingredient(in, dR);
                numIngredients++;
                return i;
            }
        }
    }
    return maxIngredients;
}

void cauldron::removeIngredient(int in)
{
    if ((0 <= in) && (in < maxIngredients))
    {
        if (ingredients[in] != nullptr) {
            numIngredients--;
            delete ingredients[in];
            ingredients[in] = nullptr;
        }
    }
}

void cauldron::distillPotion(cauldron& currCauldron,string* list,int numRemove)
{
    for (int i = 0; i < numRemove; i++) {
        if (list[i] != "") {
            for (int j = 0; j < currCauldron.maxIngredients; j++) {
                if (currCauldron.ingredients[j] != nullptr) {
                    if (currCauldron.ingredients[j]->getName() == list[i]) {
                        currCauldron.removeIngredient(j);
                        break;
                    }
                }
            }
        }
    }
}

void cauldron::listIngredients()
{
    for (int i = 0; i < maxIngredients; i++) {
        if (ingredients[i] != nullptr) {
            cout << ingredients[i]->getName() << endl;
        }
    }
}

