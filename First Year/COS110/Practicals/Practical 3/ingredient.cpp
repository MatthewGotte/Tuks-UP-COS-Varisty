#include "ingredient.h"
#include <string>

using namespace std;

ingredient::ingredient(string name,int dangerRating)
{
    this->name = name;
    this->dangerRating = dangerRating;
}

ingredient::ingredient(const ingredient* newIngredient)
{
    name = newIngredient->name;
    dangerRating = newIngredient->dangerRating;
}

ingredient::ingredient(const ingredient& newIngredient)
{
    this->name = newIngredient.name;
    this->dangerRating = newIngredient.dangerRating;
}

ingredient::~ingredient()
{

}

int ingredient::getDanger()
{
    return dangerRating;
}

string ingredient::getName()
{
    return name;
}

