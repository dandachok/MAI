#include "TList.hpp"

TList::TList() {
    head = nullptr;
    size = 0;
}

size_t TList::GetSize() {
    return this->size;
}

bool TList::IsEmpty() {
    return head == nullptr;
}

void TList::PushIndex(size_t index, std::shared_ptr<Figure>& obj) {
    if(index > size) {
        return;
    }
    else {
        std::shared_ptr<TListItem> item = head;
        for(int i = 0; i < index; i++) {
            item = item->GetNext();
        }
        std::shared_ptr<TListItem> new_item = std::make_shared<TListItem>(obj);
        new_item->SetNext(item->GetNext());
        new_item->SetPrev(item);
        item->GetNext()->SetPrev(new_item);
        item->SetNext(new_item);
        size++;
    }
}

void TList::PushLast(std::shared_ptr<Figure>& obj) {
    std::shared_ptr<TListItem> item = std::make_shared<TListItem>(obj);
    if(size == 0) {
        head = item;
        tail = item;
    }
    else {
        item->SetPrev(tail);
        tail->SetNext(item);
        tail = item;
    }
    size++;
}

void TList::PushFirst(std::shared_ptr<Figure> &obj) {
    std::shared_ptr<TListItem> item = std::make_shared<TListItem>(obj);
    if(size == 0) {
        head = item;
        tail = item;
    }
    else {
        item->SetNext(head);
        head->SetPrev(item);
        head = item;
    }
    size++;
}

std::shared_ptr<Figure> TList::PopIndex(size_t index) {
}


std::shared_ptr<Figure> TList::PopFirst() {
    if (size == 1) {
        std::shared_ptr<Figure> res = this->head->GetFigure();
        head = nullptr;
        tail = nullptr;
        size--;
        return res;
    }
    head = head->GetNext();   
    std::shared_ptr<Figure> res = head->GetPrev()->GetFigure();
    head->SetPrev(nullptr);
    size--;
    return res;
}

std::shared_ptr<Figure> TList::PopLast() {
    if (size == 1) {
        std::shared_ptr<Figure> res = head->GetFigure();
        head = nullptr;
        tail = nullptr;
        size--;
        return res;
    }
    tail = tail->GetPrev();
    std::shared_ptr<Figure> res = head->GetNext()->GetFigure();
    head->SetNext(nullptr);
    size--;
    return res;
}

TList::~TList() {
    while (head) {
        head->SetPrev(nullptr);
        head = head->GetNext();
    }
    tail = nullptr;
}

std::shared_ptr<TListItem> TList::GetHead() {
    return head;
}

std::ostream& operator<<(std::ostream& os, TList& list) {

    std::shared_ptr<TListItem> item = list.head;
    for(int i = 0; i < list.size; i++) {
      os << "id: " << i + 1 << " ";
      item->GetFigure()->Print();
      item = item->GetNext();
      os << std::endl;
    }
    os << std::endl;
    return os;
}
