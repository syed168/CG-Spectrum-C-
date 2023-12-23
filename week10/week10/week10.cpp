#include <string>
#include <iostream>

using namespace std;


// ----------------------Overloading
class Point {

public:
    int x;
    int y;

    Point(int x, int y)
        :x(x)
        ,y(y)
    {

    }
    Point()
        :x(0)
        , y(0)
    {}

    Point(int x)
        :x(x)
        , y(0)
    {}
        
    Point(string x, string y)
        :x(stoi(x))
        , y(stoi(y))
    {

    }
    // Addition: p1 + p2      
    Point operator+(const Point& other) const {

        return Point(x + other.x, y + other.y);
    }
        
    // Subtraction : p1 - p2
    Point operator-(const Point& other) const {

        return Point(x - other.x, y - other.y);
    }

    // Negation : p1 = -p2;
    Point operator-() const {

        return Point(-x, -y);
    }
    // Multiplication : p1 * 5
    Point operator*(int s) const {

        return Point(x * s, y * s);
    }
    
    // cout << ? ? ?
        
};

// Multiplication : 5 * p1
Point operator*(int s, const Point& p) {

    return Point(p.x * s, p.y * s);
}

std::ostream& operator<<(std:: ostream& left, const Point& right) {

    left << "(" << right.x << ", " << right.y << ")";
    return left;
    
}

//---------------------Enums Or Enumerators

enum class Day {
    
    MONDAY = 1, START_OF_WEEK = MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY, END_OF_WEEK = SUNDAY
};

Day& operator++(Day & d) {

    return d = (d == Day::END_OF_WEEK) ? Day::MONDAY : static_cast<Day>(static_cast<int>(d) + 1);
        
}

ostream& operator<<(ostream& left, const Day& right) {

    switch (right)
    {
    case Day:: MONDAY:
        left << "Monday";
        break;
    case Day::TUESDAY:
        left << "Tuesday";
        break;
    case Day::WEDNESDAY:
        left << "Wednesday";
        break;
    case Day::THURSDAY:
        left << "Thursday";
        break;
    case Day::FRIDAY:
        left << "Friday";
        break;
    case Day::SATURDAY:
        left << "Saturday";
        break;
    case Day::SUNDAY:
        left << "Sunday";
        break;
    default:
        left << "INVALID";
        break;
    }
    return left;
}

//------------------------Design Patterns

class Button {

protected:
    string m_Label;
public:
    Button(string label)
        :m_Label(label)
    {

    }
    virtual void Draw() = 0;

};

class CheckBox {

public:
    virtual void Draw() = 0;
};

class GUIFactory {

public:
    virtual Button* CreateButton(string label) = 0;
    virtual CheckBox* CreateCheckBox() = 0;
};

#ifdef XBOX

class XboxButton : public Button {

public:
    XboxButton(string label)
        : Button(label)
    {

    }
    virtual void Draw() override 
    {
        cout << "A: " << m_Label << endl;
    }
        
};

class XboxCheckBox : public CheckBox {

    virtual void Draw() override 
    {
        cout << "Xbox CheckBox" << endl;
    }
        
};

class XboxFactory : public GUIFactory {

    virtual Button* CreateButton(string label) override
    {
        return new XboxButton(label);
    }
        
    virtual CheckBox* CreateCheckBox() override
    {
        return new XboxCheckBox();
    }
        
};

#else

class PlaystationButton : public Button {

public:
    PlaystationButton(string label)
        : Button(label)
    {

    }
    virtual void Draw() override
    {
        cout << "X : " << m_Label << endl;
    }
        
};

class PlaystationCheckBox : public CheckBox {

    virtual void Draw() override
    {
        cout << "Playstation CheckBox" << endl;
    }
};

class PlaystationFactory : public GUIFactory {

    virtual Button* CreateButton(string label) override
    {
        return new PlaystationButton(label);
    }
    virtual CheckBox* CreateCheckBox() override
    {
        return new PlaystationCheckBox();
    }
};
#endif

GUIFactory* GetGUIFactory() {

#ifdef XBOX
    return new XboxFactory();
#else
    return new PlaystationFactory();
#endif
}



int main()
{

    // Overloading

    Point p1(10, 5);
    Point p2(5, 1);
    Point p3(2, 8);
    
    Point p4 = p1 + p2 - p3;

    cout << p4 << endl;
    cout << -p4 << endl;

    Point p5 = p1 * 5;
    Point p6 = 5 * p1;

    cout << p5 << p6 << endl;

    // Enums Or Enumerators

    Day today = Day::FRIDAY;
    if (today < Day::SATURDAY)
        cout << "Today is weekday :(" << endl;

    ++today;

    if (today > Day::FRIDAY)
        cout << "Today is weekend :)" << endl;

    ++today;
    cout << today << endl;
    ++today;
    cout << today << endl;

    //

    GUIFactory* pFactory = GetGUIFactory();
    Button* pButton = pFactory->CreateButton("Main Menu");        
    CheckBox* pCheckBox = pFactory->CreateCheckBox();

    pButton->Draw();
    pCheckBox->Draw();

    delete pButton;
    pButton = nullptr;

    delete pFactory;
    pFactory = nullptr;

    // return 0;

}

