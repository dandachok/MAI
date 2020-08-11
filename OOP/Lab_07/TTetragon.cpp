#include "TTetragon.hpp"
#include <iostream>
#include <cmath>

TTetragon::TTetragon() : TTetragon(0) {
}

TTetragon::TTetragon(int i) : side_a(i) {
    //std::cout << "TTetragon created: " << side_a << std::endl;
}

TTetragon::TTetragon(std::istream &is) {
    is >> side_a;
}

TTetragon::TTetragon(const TTetragon& orig) {
    //std::cout << "TTetragon copy created" << std::endl;
    side_a = orig.side_a;
}

int TTetragon::GetType() {
    return 3;
}

std::ostream& operator <<(std::ostream &os, const TTetragon &obj){
    os << obj.side_a;
    return os;
}

std::istream& operator>>(std::istream& is, TTetragon& obj) {
    is >> obj.side_a;
    return is;
}

bool TTetragon::operator==(const TTetragon& obj){
    return side_a == obj.side_a;
}

TTetragon& TTetragon::operator=(const TTetragon& obj) {
    if(&obj == this) {
        return *this;
    }
    side_a = obj.side_a;
    return *this;
}

double TTetragon::Square() {
  return side_a * side_a;
}

void TTetragon::Print() {
    std::cout << "a = " << side_a << std::endl;

}

TTetragon::~TTetragon() {
    //std::cout << "TTetragon deleted" << std::endl;
}
