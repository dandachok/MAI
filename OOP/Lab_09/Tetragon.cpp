#include <cmath>
#include <cstring>
#include <iostream>
#include "Tetragon.h"

#define PI 3.14159265

Tetragon::Tetragon() : Tetragon(0)
{
}

Tetragon::Tetragon(int32_t s): side(s)
{
    //std::cout << "Tetragon created: " << side << std::endl;
}

Tetragon::Tetragon(std::istream& is)
{
    std::cout << "Enter side: ";
    is >> side;
    if(side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Tetragon::Tetragon(const Tetragon& orig)
{
    side = orig.side;
}

double Tetragon::Square()
{
    return double(side * side);
}

void Tetragon::Print()
{
    std::cout << "Sides =  " << side << ", square = " << this->Square() << ", type: tetragon" << std::endl;
}

Tetragon::~Tetragon()
{
}

std::ostream& operator <<(std::ostream &os, const Tetragon &obj)
{
    os << "(" << obj.side << ")," << "type: tetragon" << std::endl;
    return os;
}

std::istream& operator >>(std::istream &is, Tetragon &obj)
{
    std::cout << "Enter side: ";
    is >> obj.side;
    return is;
}

bool Tetragon::operator ==(const Tetragon &obj) const
{
    return side == obj.side;
}


Tetragon& Tetragon::operator =(const Tetragon &obj)
{
    if (&obj == this) {
        return *this;
    }

    side = obj.side;

    return *this;
}