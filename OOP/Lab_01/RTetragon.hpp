#ifndef RTETRAGON_HPP
#define	RTETRAGON_HPP
#include <cstdlib>
#include <iostream>
#include "Figure.hpp"

class RTetragon : public Figure{
public:
    RTetragon();
    RTetragon(std::istream &is);
    RTetragon(size_t i);
    RTetragon(const RTetragon& orig);

    double Square() override;
    void   Print() override;

    virtual ~RTetragon();
private:
    size_t side_a;
};

#endif
