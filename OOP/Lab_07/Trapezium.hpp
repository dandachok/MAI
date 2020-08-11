#ifndef TRAPEZIUM_HPP
#define	TRAPEZIUM_HPP
#include <cstdlib>
#include <iostream>
#include "Figure.hpp"

class Trapezium : public Figure{
public:
    Trapezium();
    Trapezium(std::istream &is);
    Trapezium(size_t i, size_t j, size_t k, size_t l);
    Trapezium(const Trapezium& orig);

    int GetType() override;
    double Square() override;
    void   Print() override;

    virtual ~Trapezium();
private:
    size_t side_a;
    size_t side_b;
    size_t side_c;
    size_t side_d;
};

#endif
