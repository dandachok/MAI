#ifndef TQUEUEITEM_HPP
#define TQUEUEITEM_HPP

#include <iostream>
#include "TAllocationBlock.hpp"

template <class T>
class TQueueItem {
public:
    TQueueItem(const std::shared_ptr<T>& obj);

    std::shared_ptr<T> GetT();
    std::shared_ptr<TQueueItem<T>> GetNext();
    void SetNext(std::shared_ptr<TQueueItem<T>> item);
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj);

    void * operator new (size_t size);
    void operator delete (void* pointer);
    virtual ~TQueueItem() {};

private:
    std::shared_ptr<T> item;
    std::shared_ptr<TQueueItem<T>> next;

    static TAllocationBlock queueitem_allocator;
};

#endif