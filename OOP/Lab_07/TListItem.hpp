#ifndef TLISTITEM_HPP
#define TLISTITEM_HPP

#include <iostream>

template <class T>
class TListItem {
public:
    TListItem(const std::shared_ptr<T>& obj);

    std::shared_ptr<T> GetT();
    std::shared_ptr<TListItem<T>> GetNext();
    std::shared_ptr<TListItem<T>> GetPrev();
    void SetNext(std::shared_ptr<TListItem<T>> item);
    void SetPrev(std::shared_ptr<TListItem<T>> item);
    template <class A> friend std::ostream& operator<<(std::ostream& os, const TListItem<A>& obj);
    
    virtual ~TListItem() {};

private:
    std::shared_ptr<T> item;
    std::shared_ptr<TListItem<T>> next;
    std::shared_ptr<TListItem<T>> prev;
};

#endif