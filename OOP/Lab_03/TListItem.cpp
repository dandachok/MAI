#include "TListItem.hpp"
#include <iostream>

TListItem::TListItem(const std::shared_ptr<Figure>& obj){
    this->item = obj;
    this->next = nullptr;
    this->prev = nullptr;
}

std::shared_ptr<Figure> TListItem::GetFigure(){
    return item;
}

std::shared_ptr<TListItem> TListItem::GetNext(){
    return next;
}

std::shared_ptr<TListItem> TListItem::GetPrev(){
    return prev;
}

void TListItem::SetNext(std::shared_ptr<TListItem> item){
    this->next = item;
}

void TListItem::SetPrev(std::shared_ptr<TListItem> item){
    this->prev = item;
}

std::ostream& operator<<(std::ostream &os, const TListItem &obj){
    os << "(" << obj.item << ")";
    return os;
}
