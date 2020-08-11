#include <iostream>

#include "TList.hpp"

int main() {
  int act = 0;
  size_t index;
  TList list;
  TTetragon tetragon;

  std::cout << list;
  std::cout << "Choose an operation:" << std::endl;
  std::cout << "1) Add tetragon in first place" << std::endl;
  std::cout << "2) Add tetragon in last place" << std::endl;
  std::cout << "3) Add tetragon at index" << std::endl;
  std::cout << "4) Delete tetragon from first place of list" << std::endl;
  std::cout << "5) Delete tetragon from last place of list" << std::endl;
  std::cout << "6) Delete tetragon from list at index" << std::endl;
  std::cout << "7) Print list"  << std::endl;
  std::cout << "0) Exit" << std::endl;
  while (std::cin >> act && act) {
    switch(act) {
      case 1: {
        std::cin >> tetragon;
        list.PushFirst(tetragon);
        break;
      }
      case 2: {
        std::cin >> tetragon;
        list.PushLast(tetragon);
        break;
      }
      case 3: {
        std::cin >> index >> tetragon;
        list.PushIndex(index, tetragon);
        break;
      }
      case 4: {
        std::cout << list.PopFirst();
        break;
      }
      case 5: {
        std::cout << list.PopLast();
        break;
      }
      case 6: {
        std::cin >> index;
        std::cout << list.PopIndex(index);
        break;
      }
      case 7: {
        std::cout << list;
        break;
      }
      default: {
        std::cout << "Incorrect command" << std::endl;;
        break;
      }
    }
  }

  return 0;
}
