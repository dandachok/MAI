#ifndef TETRAGON_H
#define TETRAGON_H

#include <iostream>
#include <cstdint>
#include "figure.h"

class Tetragon : public Figure
{
public:
    Tetragon();
    Tetragon(std::istream &is);
    Tetragon(int32_t side);
    Tetragon(const Tetragon &orig);

    bool operator ==(const Tetragon &obj) const;
    Tetragon& operator =(const Tetragon &obj);
    friend std::ostream& operator <<(std::ostream &os, const Tetragon &obj);
    friend std::istream& operator >>(std::istream &is, Tetragon &obj);

    double Square() override;
    void Print() override;
    virtual ~Tetragon();

private:
    int32_t side;
};


#endif /*Tetragon_H */