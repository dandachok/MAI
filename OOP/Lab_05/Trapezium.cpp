#include "Trapezium.hpp"
#include <iostream>
#include <cmath>

Trapezium::Trapezium() : Trapezium(0, 0, 0, 0) {
}

Trapezium::Trapezium(size_t i, size_t j, size_t k, size_t l) : side_a(i), side_b(j), side_c(k), side_d(l) {
    std::cout << "Trapezium created: " << side_a << ", " << side_b << std::endl;
}

Trapezium::Trapezium(std::istream &is) {
    is >> side_a;
    is >> side_b;
    is >> side_c;
    is >> side_d;
}

Trapezium::Trapezium(const Trapezium& orig) {
    std::cout << "Trapezium copy created" << std::endl;
    side_a = orig.side_a;
    side_b = orig.side_b;
    side_c = orig.side_c;
    side_d = orig.side_d;
}

double Trapezium::Square() {
  double x = (side_b * side_b + (side_a - side_c) * (side_a - side_c) - side_d * side_d) / (2 * (side_a - side_c));
  double h = sqrt(side_b * side_b - x * x);
  double s = (side_a + side_c) * h / 2;
  return s;
}

void Trapezium::Print() {
    std::cout << "a = " << side_a << ", b = " << side_b << ", c = " << side_c << ", d = " << side_d << std::endl;

}

Trapezium::~Trapezium() {
    std::cout << "Trapezium deleted" << std::endl;
}
