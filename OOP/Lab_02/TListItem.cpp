#include "TListItem.hpp"
#include <iostream>

TListItem::TListItem(const TTetragon &obj){
    this->item = obj;
    this->next = nullptr;
    this->prev = nullptr;
}

TTetragon TListItem::GetFigure(){
    return item;
}

TListItem* TListItem::GetNext(){
    return next;
}

TListItem* TListItem::GetPrev(){
    return prev;
}

void TListItem::SetNext(TListItem *item){
    this->next = item;
}

void TListItem::SetPrev(TListItem *item){
    this->prev = item;
}

std::ostream& operator<<(std::ostream &os, const TListItem &obj){
    os << "(" << obj.item << ")";
    return os;
}
