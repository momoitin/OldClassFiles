
#include <iostream>
#include "classes.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
//              Circle Class
//////////////////////////////////////////////////////////////////////////////////////////

/*  Private Data
double radius;
double center_x;
double center_y;
*/

Circle::Circle() //this is a constructor with no parameters
{                //    known as "default constructor"
    radius = 1;
    center_x = 0;
    center_y = 0;
}

Circle::Circle(double r) //this is a constructor with one parameter
{
    radius = r;
    center_x = 0;
    center_y = 0;
}

void Circle::SetCenter(double x, double y) //setter for the center
{
    center_x = x;
    center_y = y;
}

void Circle::SetRadius(double r) //setter for the redius
{
    if (r <= 0)
    {
        return;
    }
    radius = r;
}

void Circle::Draw()
{
    std::cout << "radius: " << radius << std::endl;
    std::cout << "x int: " << center_x << std::endl;
    std::cout << "y int: " << center_y << std::endl;
}

double Circle::GetArea() const
{
    double area = 3.14 * radius * radius;
    return area;
}

//////////////////////////////////////////////////////////////////////////////////////////
//              Fraction Class
//////////////////////////////////////////////////////////////////////////////////////////

/*  Private Data
int numerator;   //can be anything
int denominator; //cannot be zero
*/

Fraction::Fraction() //default constructor for 0/1
{
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int n) //constructor for numerator / 1
{
    numerator = n;
    denominator = 1;
}

Fraction::Fraction(int n, int d) //constructor for numerator / denominator
{
    numerator = n;
    denominator = d;
}

void Fraction::setValue(int n, int d)
{
    numerator = n;
    denominator = d;
}

void Fraction::setNumerator(int n) //setter for numerator
{
    numerator = n;
}

void Fraction::setDenominator(int d) //setter for denominator
{
    if (d == 0)
    {
        return;
    }
    denominator = d;
}

int Fraction::getNumerator() const //gets numerator
{
    return numerator;
}

int Fraction::getDenominator() const //gets denominator
{
    return denominator;
}

void Fraction::Input()
{
    char garbage;
    cin >> numerator >> garbage >> denominator; //inputs in the form "n/d"
}

void Fraction::Show()
{
    cout << "Fraction: " << numerator << "/" << denominator << endl;
}

double Fraction::Evaluate() const
{
    return (double)numerator / (double)denominator;
}

//////////////////////////////////////////////////////////////////////////////////////////
//              Character Class
//////////////////////////////////////////////////////////////////////////////////////////

/*
    Private Data
    //stats
    int strength;     //must be less than 20 and greater than 6
    int dexterity;    //must be less than 20 and greater than 6
    int constitution; //must be less than 20 and greater than 6
    int intelligence; //must be less than 20 and greater than 6
    int wisdom;       //must be less than 20 and greater than 6
    int charisma;     //must be less than 20 and greater than 6
    //personal data
    string Name; //
    string Race; //
    int classLevel;

    enum charClass
    {
        Artificer,
        Barbarian,
        Bard,
        Cleric,
        Druid,
        Fighter,
        Monk,
        Paladin,
        Ranger,
        Rogue,
        Sorcerer,
        Warlock,
        Wizard
    };
*/

//Constructors
Character::Character()
{
    Name = "Steve";
}

Character::Character(string n) //default character constructor;
{
    Name = n;
}
// Character::Character(int s, int d, int co, int i, int w, int ch) //creates a new character with stats
// {
//     Character::setAllStats(s, d, co, i, w, ch);
// }
//Setters

Character::~Character() //Deconstructor for Character
{
    cout << "Running Destructor on: Name = " << Name << endl;
}

void Character::setAllStats(int s, int d, int co, int i, int w, int ch)
{
    strength = checkStats(s, "strength");
    dexterity = checkStats(d, "dexterity");
    constitution = checkStats(co, "constitution");
    intelligence = checkStats(i, "intelligence");
    wisdom = checkStats(w, "wisdom");
    charisma = checkStats(ch, "charisma");
}
void Character::setStrength(int s)
{
    strength = checkStats(s, "strength");
}
void Character::setDexterity(int d)
{
    dexterity = checkStats(d, "dexterity");
}
void Character::setConstitution(int co)
{
    constitution = checkStats(co, "constitution");
}
void Character::setIntelligence(int i)
{
    intelligence = checkStats(i, "intelligence");
}
void Character::setWisdom(int w)
{
    wisdom = checkStats(w, "wisdom");
}
void Character::setCharisma(int ch)
{
    charisma = checkStats(ch, "charisma");
}

void Character::setName(string n)
{
    Name = n;
}
void Character::setRace(string r)
{
    Race = r;
}
void Character::setClass()
{
    cout << "Select a class from the list below:\n"
         << "1) Artificer\n"
         << "2) Barbarian\n"
         << "3) Bard\n"
         << "4) Cleric\n"
         << "5) Druid\n"
         << "6) Fighter\n"
         << "7) Monk\n"
         << "8) Paladin\n"
         << "9) Ranger\n"
         << "10) Rogue\n"
         << "11) Sorcerer\n"
         << "12) Warlock\n"
         << "13) Wizard\n";
    int setClass;
    cin >> setClass;

    classType = setClass - 1;
}

//Getters
void Character::getStats() const
{
    cout << "Character Stats:\n"
         << "Strength:     " << strength << endl
         << "Dexterity:    " << dexterity << endl
         << "Constitution: " << constitution << endl
         << "Intelligence: " << intelligence << endl
         << "Wisdom:       " << wisdom << endl
         << "Charisma:     " << charisma << endl;
}
void Character::getName() const
{
    cout << "Name: " << Name << endl;
}
void Character::getRace() const
{
    cout << "Race: " << Race << endl;
}
void Character::getClass() const
{
}
void Character::getCharacterSheet() const
{
    Character::getName();
    // Character::getClass();
    Character::getRace();
    Character::getStats();
}

int Character::checkStats(int stat, string statName)
{
    while (stat > 20 || stat < 6)
    {
        cout << "Please enter a valid stat for " << statName << " (6-20): ";
        cin >> stat;
    }
    return stat;
}