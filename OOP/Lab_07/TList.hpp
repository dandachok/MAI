#ifndef TLIST_HPP
#define TLIST_HPP

#include "TListItem.hpp"
#include "TIterator.hpp"
#include "IRemoveCriteria.hpp"

template <class T, class TT>
class TList{
public:
    TList();

    size_t GetSize();
    bool IsEmpty();

    void InsertSubitem(std::shared_ptr<TT>& item);
    void RemoveSubitem(IRemoveCriteria<TT>& criteria);
    void PushFirst(std::shared_ptr<T>& obj);
    void PushLast(std::shared_ptr<T>& obj);
    void PushIndex(size_t index, std::shared_ptr<T>& obj);
    std::shared_ptr<T> PopFirst();
    std::shared_ptr<T> PopLast();
    std::shared_ptr<T> PopIndex(size_t index);
    std::shared_ptr<TListItem<T>> GetHead();
    std::shared_ptr<TListItem<T>> GetTail();

    TIterator<TListItem<T>, T> begin() const;
    TIterator<TListItem<T>, T> end() const;

    template <class A, class AA> friend std::ostream& operator<<(std::ostream& os, const TList<A, AA>& list);

    virtual ~TList();

private:
    size_t size;
    std::shared_ptr<TListItem<T>> head;
    std::shared_ptr<TListItem<T>> tail;
};

#endif