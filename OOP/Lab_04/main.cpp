#include <iostream>
#include "Figure.hpp"
#include "TTetragon.hpp"
#include "Rectangle.hpp"
#include "Trapezium.hpp"
#include "TList.hpp"

void menu() {
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "1) Add trapezium" << std::endl;
    std::cout << "2) Add tetragon" << std::endl;
    std::cout << "3) Add rectangle" << std::endl;
    std::cout << "4) Delete figure from list" << std::endl;
    std::cout << "5) Print list"  << std::endl;
    std::cout << "0) Exit" << std::endl;
}

int main() {
  int32_t act = 0;
    TList<Figure> list;
    std::shared_ptr<Figure> ptr;
    do {
        menu();
        std::cin >> act;
        switch(act) {
            case 1:
                ptr = std::make_shared<Trapezium>(std::cin);
                list.PushLast(ptr);
                break;
            case 2:
                ptr = std::make_shared<TTetragon>(std::cin);
                list.PushLast(ptr);
                break;
            case 3:
                ptr = std::make_shared<Rectangle>(std::cin);
                list.PushLast(ptr);
                break;
            case 4:
                list.PopFirst();
                break;
            case 5:
                std::cout << list << std::endl;
                break;
            case 0:
                std::cout << "Exit";
                break;
            default:
                std::cout << "Incorrect command" << std::endl;;
                break;
        }
    } while (act);

  return 0;
}
