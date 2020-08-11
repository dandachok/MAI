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

void TList::PushIndex(size_t index, TTetragon& obj) {
    if(index > size) {
        return;
    }
    else {
        TListItem* item = head;
        for(int i = 0; i < index; i++) {
            item = item->GetNext();
        }
        TListItem* new_item = new TListItem(obj);
        new_item->SetNext(item->GetNext());
        new_item->SetPrev(item);
        item->GetNext()->SetPrev(new_item);
        item->SetNext(new_item);
        size++;
    }
}

void TList::PushLast(TTetragon& obj) {
    TListItem* item = new TListItem(obj);
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

void TList::PushFirst(TTetragon &obj) {
    TListItem* item = new TListItem(obj);
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

TTetragon TList::PopIndex(size_t index) {
    TListItem *tmp = this->head;
    for(size_t i = 0; i < index - 1; ++i) {
        tmp = tmp->GetNext();
    }
    TListItem *removed = tmp->GetNext();
    TTetragon res = removed->GetFigure();
    TListItem *nextItem = removed->GetNext();
    tmp->SetNext(nextItem);
    nextItem->SetPrev(tmp);
    delete removed;
    return res;
}


TTetragon TList::PopFirst() {
    if (size == 1) {
        TTetragon res = this->head->GetFigure();
        delete this->head;
        head = nullptr;
        tail = nullptr;
        size--;
        return res;
    }
    head = head->GetNext();   
    TTetragon res = head->GetPrev()->GetFigure();
    delete head->GetPrev();
    head->SetPrev(nullptr);
    size--;
    return res;
}

TTetragon TList::PopLast() {
    if (size == 1) {
        TTetragon res = head->GetFigure();
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return res;
    }
    tail = tail->GetPrev();
    TTetragon res = head->GetNext()->GetFigure();
    delete head->GetNext();
    head->SetNext(nullptr);
    size--;
    return res;
}

TList::~TList() {
    TListItem* tmp;
    while (head) {
        tmp = head;
        head = head->GetNext();
        delete tmp;
    }
}

TListItem* TList::GetHead() {
    return head;
}

std::ostream& operator<<(std::ostream& os, TList& list) {

    TListItem *item = list.tail;
    while(item!=nullptr) {
      os << *item << " ";
      item = item->GetPrev();
    }
    os << std::endl;
    return os;
}
