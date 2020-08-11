#ifndef TLIST_HPP
#define TLIST_HPP

#include "TListItem.hpp"

class TList{
public:
    TList();

    size_t GetSize();
    bool IsEmpty();

    void PushFirst(std::shared_ptr<Figure>& obj);
    void PushLast(std::shared_ptr<Figure>& obj);
    void PushIndex(size_t index, std::shared_ptr<Figure>& obj);
    std::shared_ptr<Figure> PopFirst();
    std::shared_ptr<Figure> PopLast();
    std::shared_ptr<Figure> PopIndex(size_t index);
    std::shared_ptr<TListItem> GetHead();
    std::shared_ptr<TListItem> GetTail();

    friend std::ostream& operator<<(std::ostream&, TList& list);

    virtual ~TList();

private:
    size_t size;
    std::shared_ptr<TListItem> head;
    std::shared_ptr<TListItem> tail;
};

#endif