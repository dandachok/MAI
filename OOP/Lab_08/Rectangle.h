#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <cstdint>
#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle();
    Rectangle(std::istream &is);
    Rectangle(int32_t side_a, int32_t side_b);
    Rectangle(const Rectangle& orig);

    bool operator ==(const Rectangle &obj) const;
    Rectangle& operator =(const Rectangle &obj);
    friend std::ostream& operator <<(std::ostream &os, const Rectangle &obj);
    friend std::istream& operator >>(std::istream &is, Rectangle &obj);

    double Square() override;
    void Print() override;
    virtual ~Rectangle();

private:
    int32_t side_a;
    int32_t side_b;
};

#endif /* Rectangle_H */