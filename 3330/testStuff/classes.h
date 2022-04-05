using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
//              Circle Class
//////////////////////////////////////////////////////////////////////////////////////////

class Circle
{
public:
    Circle();         //this is a constructor with no parameters
                      //    known as "default constructor"
    Circle(double r); //this is a constructor with one parameter
    ~Circle();

    void SetCenter(double x, double y); //setter for the center
    void SetRadius(double r);           //setter for the redius

    void Draw();

    double GetArea() const;

private:
    double radius;
    double center_x;
    double center_y;
};

//////////////////////////////////////////////////////////////////////////////////////////
//              Fraction Class
//////////////////////////////////////////////////////////////////////////////////////////

class Fraction
{
public:
    Fraction();             //default constructor for 0/1
    Fraction(int n);        //constructor for numerator / 1
    Fraction(int n, int d); //constructor for numerator / denominator
    ~Fraction();            //destructor

    // explicit Fraction(Character x);

    void setValue(int n, int d);
    void setNumerator(int n);   //setter for numerator
    void setDenominator(int d); //setter for denominator

    int getNumerator() const;   //gets numerator
    int getDenominator() const; //gets denominator

    void Input();
    void Show();

    double Evaluate() const; //returns numerator / denominator

private:
    int numerator;   //can be anything
    int denominator; //cannot be zero
};

//////////////////////////////////////////////////////////////////////////////////////////
//              Character Class
//////////////////////////////////////////////////////////////////////////////////////////

class Character
{
public:
    //Constructors
    Character();
    Character(string n); //default character constructor;
    // Character(int s, int d, int co, int i, int w, int ch); //creates a new character with stats
    ~Character(); //destructor for character

    //Setters
    void setAllStats(int s, int d, int co, int i, int w, int ch);
    void setStrength(int s);
    void setDexterity(int d);
    void setConstitution(int co);
    void setIntelligence(int i);
    void setWisdom(int w);
    void setCharisma(int ch);

    void setName(string n);
    void setRace(string r);
    void setClass(); //opens a class selection menu

    //Getters
    void getStats() const;
    void getName() const;
    void getRace() const;
    void getClass() const;
    void getCharacterSheet() const;

    //mutators
    int checkStats(int stat, string statName);

private:
    //stats
    int strength;     //must be less than 20 and greater than 6
    int dexterity;    //must be less than 20 and greater than 6
    int constitution; //must be less than 20 and greater than 6
    int intelligence; //must be less than 20 and greater than 6
    int wisdom;       //must be less than 20 and greater than 6
    int charisma;     //must be less than 20 and greater than 6
    //personal data
    string Name; //takes any string input
    string Race; //takes any string input
    int classType;
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
};