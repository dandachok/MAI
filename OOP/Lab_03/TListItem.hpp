#ifndef TLISTITEM_HPP
#define TLISTITEM_HPP

#include <iostream>
#include "Rectangle.hpp"
#include "TTetragon.hpp"
#include "Trapezium.hpp"

class TListItem {
public:
    TListItem(const std::shared_ptr<Figure>& obj);

    std::shared_ptr<Figure> GetFigure();
    std::shared_ptr<TListItem> GetNext();
    std::shared_ptr<TListItem> GetPrev();
    void SetNext(std::shared_ptr<TListItem> item);
    void SetPrev(std::shared_ptr<TListItem> item);
    friend std::ostream& operator<<(std::ostream& os, const TListItem& obj);

    virtual ~TListItem() {};
private:
    std::shared_ptr<Figure> item;
    std::shared_ptr<TListItem> next;
    std::shared_ptr<TListItem> prev;
};

#endif