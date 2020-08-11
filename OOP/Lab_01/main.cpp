#include <iostream>

#include "RTetragon.hpp"
#include "Rectangle.hpp"
#include "Trapezium.hpp"

int main() {

  Figure *q = new RTetragon(std::cin);
  q->Print();
  std::cout << q->Square() << std::endl;
  delete q;

  Figure *r = new Rectangle(std::cin);
  r->Print();
  std::cout << r->Square() << std::endl;
  delete r;

  Figure *t = new Trapezium(std::cin);
  t->Print();
  std::cout << t->Square() << std::endl;
  delete t;
  
  return 0;
}
