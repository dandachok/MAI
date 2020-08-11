#ifndef TLISTITEM_HPP
#define TLISTITEM_HPP

#include <iostream>
#include "TTetragon.hpp"

class TListItem {
public:
    TListItem(const TTetragon& obj);

    TTetragon GetFigure();
    TListItem* GetNext();
    TListItem* GetPrev();
    void SetNext(TListItem *item);
    void SetPrev(TListItem *item);
    friend std::ostream& operator<<(std::ostream& os, const TListItem &obj);

    virtual ~TListItem() {};
private:
    TTetragon item;
    TListItem* next;
    TListItem* prev;
};

#endif