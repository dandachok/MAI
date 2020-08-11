#include <iostream>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <random>
#include "Trapezium.h"
#include "Rectangle.h"
#include "Tetragon.h"
#include "TList.h"


int main(void)
{
    TList<Figure> list;
    typedef std::function<void(void)> Command;
    TQueue<std::shared_ptr<Command>> queue;
    std::mutex mtx;

    Command cmdInsert = [&]() {
        std::lock_guard<std::mutex> guard(mtx);

        uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::default_random_engine generator(seed);
        std::uniform_int_distribution<int> distFigureType(1, 3);
        std::uniform_int_distribution<int> distFigureParam(1, 10);
        for (int i = 0; i < 5; ++ i) {
            std::cout << "Command: Insert" << std::endl;

            switch(distFigureType(generator)) {
                case 1: {
                    std::cout << "Inserted trapeze" << std::endl;

                    int32_t big_base = distFigureParam(generator);
                    int32_t small_base = distFigureParam(generator);
                    int32_t l_side = distFigureParam(generator);
                    int32_t r_side = distFigureParam(generator);

                    list.PushFirst(std::shared_ptr<Trapeze>(new Trapeze(small_base, big_base, l_side, r_side)));

                    break;
                }

                case 2: {
                    std::cout << "Inserted Rectangle" << std::endl;

                    int32_t side_a = distFigureParam(generator);
                    int32_t side_b = distFigureParam(generator);

                    list.PushFirst(std::shared_ptr<Rectangle>(new Rectangle(side_a, side_b)));

                    break;
                }

                case 3: {
                    std::cout << "Inserted Tetragon" << std::endl;

                    int32_t side = distFigureParam(generator);

                    list.PushFirst(std::shared_ptr<Tetragon>(new Tetragon(side)));

                    break;
                }
            }
        }
    };


    Command cmdRemove = [&]() {
        std::lock_guard<std::mutex> guard(mtx);

        std::cout << "Command: Remove" << std::endl;

        if (list.IsEmpty()) {
            std::cout << "List is empty" << std::endl;
        } else {
            uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();

            std::default_random_engine generator(seed);
            std::uniform_int_distribution<int> distSquare(1, 150);
            double sqr = distSquare(generator);
            std::cout << "Lesser than " << sqr << std::endl;

            for (int32_t i = 0; i < 5; ++i) {
                auto iter = list.begin();
                for (int32_t k = 0; k < list.GetLength(); ++k) {
                    if (iter->Square() < sqr) {
                        list.Pop(k);
                        break;
                    }
                    ++iter;
                }
            }
        }
    };

    Command cmdPrint = [&]() {
        std::lock_guard<std::mutex> guard(mtx);

        std::cout << "Command: Print" << std::endl;
        if(!list.IsEmpty()) {
            std::cout << list << std::endl;
        } else {
            std::cout << "List is empty." << std::endl;
        }
    };

    queue.Push(std::shared_ptr<Command>(&cmdPrint, [](Command*){}));
    queue.Push(std::shared_ptr<Command>(&cmdRemove, [](Command*){}));
    queue.Push(std::shared_ptr<Command>(&cmdPrint, [](Command*){}));
    queue.Push(std::shared_ptr<Command>(&cmdInsert, [](Command*){}));

    while (!queue.IsEmpty()) {
        std::shared_ptr<Command> cmd = queue.Top();
        std::future<void> ft = std::async(*cmd);
        ft.get();
        queue.Pop();
    }

    return 0;
}
