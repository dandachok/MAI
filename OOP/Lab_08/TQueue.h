#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <memory>
#include "TQueueItem.h"

template <class T>
class TQueue
{
public:
    TQueue();
    virtual ~TQueue();

    void Push(const T &item);
    void Pop();
    T &Top();
    bool IsEmpty() const;
    uint32_t GetSize() const;

    template <class A> friend std::ostream& operator<<(std::ostream &os, const TQueue<A> &queue);

private:
    TQueueItem<T> *head;
    uint32_t count;
};

#endif