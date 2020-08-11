#include "RTetragon.hpp"
#include <iostream>
#include <cmath>

RTetragon::RTetragon() : RTetragon(0) {
}

RTetragon::RTetragon(size_t i) : side_a(i) {
    std::cout << "RTetragon created: " << side_a << std::endl;
}

RTetragon::RTetragon(std::istream &is) {
    is >> side_a;
}

RTetragon::RTetragon(const RTetragon& orig) {
    std::cout << "RTetragon copy created" << std::endl;
    side_a = orig.side_a;
}

double RTetragon::Square() {
  return side_a * side_a;
}

void RTetragon::Print() {
    std::cout << "a=" << side_a << std::endl;

}

RTetragon::~RTetragon() {
    std::cout << "RTetragon deleted" << std::endl;
}
