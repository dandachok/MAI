#ifndef TLIST_HPP
#define TLIST_HPP

#include "TListItem.hpp"

template <class T>
class TList{
public:
    TList();

    size_t GetSize();
    bool IsEmpty();

    void PushFirst(std::shared_ptr<T>& obj);
    void PushLast(std::shared_ptr<T>& obj);
    void PushIndex(size_t index, std::shared_ptr<T>& obj);
    std::shared_ptr<T> PopFirst();
    std::shared_ptr<T> PopLast();
    std::shared_ptr<T> PopIndex(size_t index);
    std::shared_ptr<TListItem<T>> GetHead();
    std::shared_ptr<TListItem<T>> GetTail();

    template <class A> friend std::ostream& operator<<(std::ostream& os, const TList<A>& list);

    virtual ~TList();

private:
    size_t size;
    std::shared_ptr<TListItem<T>> head;
    std::shared_ptr<TListItem<T>> tail;
};

#endif