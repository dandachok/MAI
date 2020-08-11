#ifndef TQUEUE_HPP
#define TQUEUE_HPP

#include "TQueueItem.hpp"
#include <iostream>

template <class T>
class TQueue {
public:
    TQueue();
    
    bool IsEmpty();
    size_t Size();
    void Push(T& item);
    T Pop();

    ~TQueue();
private:
    TQueueItem<T>* head;
    TQueueItem<T>* tail;
    size_t size;
};

#endif