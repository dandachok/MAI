#ifndef TQUEUE_HPP
#define TQUEUE_HPP

#include "TQueueItem.hpp"
#include "TIterator.hpp"

template <class T>
class TQueue{
public:
    TQueue();

    size_t GetSize();
    bool IsEmpty();

    void Push(std::shared_ptr<T>& obj);
    std::shared_ptr<T> Pop();
    std::shared_ptr<TQueueItem<T>> GetHead();

    TIterator<TQueueItem<T>, T> begin();
    TIterator<TQueueItem<T>, T> end();

    template <class A> friend std::ostream& operator<<(std::ostream& os, TQueue<A>& queue);

    virtual ~TQueue();

private:
    size_t size;
    std::shared_ptr<TQueueItem<T>> head;
    std::shared_ptr<TQueueItem<T>> tail;
};

#endif