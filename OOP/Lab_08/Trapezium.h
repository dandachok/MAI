#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <iostream>
#include <cstdint>
#include "figure.h"

class Trapeze : public Figure
{
public:
    Trapeze();
    Trapeze(std::istream &is);
    Trapeze(int32_t small_base, int32_t big_base, int32_t l_side, int32_t r_side);
    Trapeze(const Trapeze &orig);

    bool operator ==(const Trapeze &obj) const;
    Trapeze& operator =(const Trapeze &obj);
    friend std::ostream& operator <<(std::ostream &os, const Trapeze &obj);
    friend std::istream& operator >>(std::istream &is, Trapeze &obj);

    double Square() override;
    void Print() override;
    virtual ~Trapeze();

private:
    int32_t small_base;
    int32_t big_base;
    int32_t l_side;
    int32_t r_side;
};

#endif /* TRAPEZE_H */
