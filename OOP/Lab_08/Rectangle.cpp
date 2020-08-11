#include <iostream>
#include <cmath>
#include "Rectangle.h"

#define PI 3.14159265


Rectangle::Rectangle() : Rectangle(0, 0)
{
}

Rectangle::Rectangle(int32_t s, int32_t ang): side_a(s), side_b(ang)
{
    if (side_b > 180) {
        side_b %= 180;
    }
    if (side_b > 90) {
        side_b = 180 - side_b;
    }
    //std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
}

Rectangle::Rectangle(std::istream &is)
{
    std::cout << "Enter side: ";
    is >> side_a;
    std::cout << "Enter smaller angle: ";
    is >> side_b;
    if (side_b > 90 && side_b < 180) {
        side_b = 180 - side_b;
    }
    if(side_a < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    if(side_b < 0 || side_b > 180) {
        std::cerr << "Error: angles should be > 0 and < 180." << std::endl;
    }
}

Rectangle::Rectangle(const Rectangle& orig)
{
    side_a = orig.side_a;
    side_b = orig.side_b;
}

double Rectangle::Square()
{
    return (double)(side_a * side_b);
}

void Rectangle::Print()
{
    std::cout << "Side = " << side_a << ", side_b = " << side_b << ", square = " << this->Square() << ", type: Rectangle" << std::endl;
}

Rectangle::~Rectangle()
{
}

std::ostream& operator <<(std::ostream &os, const Rectangle &obj)
{
     os << "(" << obj.side_a << " " << obj.side_b << ")," << "type: Rectangle" << std::endl;
    return os;
}

std::istream& operator >>(std::istream &is, Rectangle &obj)
{
    std::cout << "Enter side: ";
    is >> obj.side_a;
    std::cout << "Enter smaller angle: ";
    is >> obj.side_b;
    return is;
}

bool Rectangle::operator ==(const Rectangle &obj) const
{
    return side_b == obj.side_b && side_a == obj.side_a;
}


Rectangle& Rectangle::operator =(const Rectangle &obj)
{
    if (&obj == this) {
        return *this;
    }

    side_b = obj.side_b;
    side_a = obj.side_a;

    return *this;
}
