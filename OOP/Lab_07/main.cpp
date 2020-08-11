#include <iostream>
#include "Figure.hpp"
#include "TTetragon.hpp"
#include "Rectangle.hpp"
#include "Trapezium.hpp"
#include "TList.hpp"
#include "TQueue.hpp"
#include "Figure.hpp"
#include "IRemoveCriteria.hpp"
#include "IRemoveCriteriaByType.hpp"
#include "IRemoveCriteriaByValue.hpp"

void menu() {
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "1) Add trapezium in queue" << std::endl;
    std::cout << "2) Add rectangle" << std::endl;
    std::cout << "3) Add tetragon" << std::endl;
    std::cout << "4) Remove" << std::endl;
    std::cout << "5) Print list" << std::endl;
    std::cout << "0) Exit" << std::endl;
}

void menu_remove() {
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "1) By type " << std::endl;
    std::cout << "2) By square" << std::endl;
}

int main() {
    int32_t act = 0;
    int flag;
    int type;
    int square;
    TList<TQueue<Figure>, Figure> list;
    std::shared_ptr<TQueue<Figure>> queue = std::make_shared<TQueue<Figure>>();
    std::shared_ptr<Figure> ptr;
    do {
        menu();
        std::cin >> act;
        switch(act) {
            case 1:
                ptr = std::make_shared<Trapezium>(std::cin);
                list.InsertSubitem(ptr);
                break;
            case 2:
                ptr = std::make_shared<Rectangle>(std::cin);
                list.InsertSubitem(ptr);
                break;
            case 3:
                ptr = std::make_shared<TTetragon>(std::cin);
                list.InsertSubitem(ptr);
                break;
            case 4:
                menu_remove();
			    std::cin >> flag;
			    if (flag == 1) {
				    std::cout << "1. All Trapezium" << std::endl;
				    std::cout << "2. All Rectangle" << std::endl;
				    std::cout << "3. All Tetragon" << std::endl;
				    std::cin >> type;
				    if (type == 1) {
					    IRemoveCriteriaByType<Figure> criteria(1);
					    list.RemoveSubitem(criteria);
				    }
				    else if (type == 2) {
					    IRemoveCriteriaByType<Figure> criteria(2);
					    list.RemoveSubitem(criteria);
				    }
				    else if (type == 3) {
					    IRemoveCriteriaByType<Figure> criteria(3);
					    list.RemoveSubitem(criteria);
				    }
                }
			    else {
				std::cout << "Insert Square:";
				std::cin >> square;
				IRemoveCriteriaByValue<Figure> criteria(square);
				list.RemoveSubitem(criteria);
			    }
                break;
            case 5:
                std::cout << list;
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
