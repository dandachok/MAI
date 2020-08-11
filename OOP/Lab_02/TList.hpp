#ifndef TLIST_HPP
#define TLIST_HPP

#include "TListItem.hpp"

class TList{
public:
    TList();

    size_t GetSize();
    bool IsEmpty();

    void PushFirst(TTetragon& obj);
    void PushLast(TTetragon& obj);
    void PushIndex(size_t index, TTetragon& obj);
    TTetragon PopFirst();
    TTetragon PopLast();
    TTetragon PopIndex(size_t index);
    TListItem* GetHead();

    friend std::ostream& operator<<(std::ostream&, TList& list);

    virtual ~TList();

private:
    size_t size;
    TListItem* head;
    TListItem* tail;
};

#endif