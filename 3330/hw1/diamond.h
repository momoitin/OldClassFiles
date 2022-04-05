using namespace std;

class Diamond
{
public:
    Diamond(int l, char b = '#', char f = '*'); //constructor for Diamond(Length, Border, Fill)
                                                //with default values

    //Getters
    int GetSize() const;    //returns the size of a side
    double Perimeter() const; //returns the perimeter of the diamond
    double Area() const;      //returns the area of the diamond

    //Setters
    void SetBorder(char b); //sets the border character
    void SetFill(char f);

    //mutators
    void Grow();   //increases the size of the diamond by 1 (range 1-39)
    void Shrink(); //decreases the size of the diamond by 1 (range 1-39)

    //display
    void Draw() const;    //displays a picture of the diamond
    void Summary() const; //displays size, perimeter, area, and picture of the diamond

private:
    int length;
    char border;
    char fill;
};
