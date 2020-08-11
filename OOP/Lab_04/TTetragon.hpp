#ifndef TTETRAGON_HPP
#define	TTETRAGON_HPP
#include <cstdlib>
#include <iostream>
#include "Figure.hpp"

class TTetragon : public Figure{
public:
    TTetragon();
    TTetragon(std::istream &is);
    TTetragon(int i);
    TTetragon(const TTetragon& orig);

    friend std::ostream& operator<<(std::ostream& os, const TTetragon& obj);
    friend std::istream& operator>>(std::istream& is, TTetragon& obj);
    bool operator==(const TTetragon& obj);
    TTetragon& operator=(const TTetragon& obj);

    double Square() override;
    void   Print() override;

    virtual ~TTetragon();
private:
    size_t side_a;
};

#endif
