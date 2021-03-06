#ifndef RECTANGLE_HPP
#define	RECTANGLE_HPP
#include <cstdlib>
#include <iostream>
#include "Figure.hpp"

class Rectangle : public Figure{
public:
    Rectangle();
    Rectangle(std::istream &is);
    Rectangle(size_t i,size_t j);
    Rectangle(const Rectangle& orig);

    int GetType() override;
    double Square() override;
    void   Print() override;

    virtual ~Rectangle();
private:
    size_t side_a;
    size_t side_b;
};

#endif
