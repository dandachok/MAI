#include "TList.hpp"

template <class T>
TList<T>::TList() {
    head = nullptr;
    size = 0;
}

template <class T>
size_t TList<T>::GetSize() {
    return this->size;
}

template <class T>
bool TList<T>::IsEmpty() {
    return head == nullptr;
}

template <class T>
void TList<T>::PushIndex(size_t index, std::shared_ptr<T>& obj) {
    if(index > size) {
        return;
    }
    else {
        std::shared_ptr<TListItem<T>> item = head;
        for(int i = 0; i < index; i++) {
            item = item->GetNext();
        }
        std::shared_ptr<TListItem<T>> new_item = std::make_shared<TListItem<T>>(obj);
        new_item->SetNext(item->GetNext());
        new_item->SetPrev(item);
        item->GetNext()->SetPrev(new_item);
        item->SetNext(new_item);
        size++;
    }
}

template <class T>
void TList<T>::PushLast(std::shared_ptr<T>& obj) {
    std::shared_ptr<TListItem<T>> item = std::make_shared<TListItem<T>>(obj);
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

template <class T>
void TList<T>::PushFirst(std::shared_ptr<T> &obj) {
    std::shared_ptr<TListItem<T>> item = std::make_shared<TListItem<T>>(obj);
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

template <class T>
std::shared_ptr<T> TList<T>::PopIndex(size_t index) {
    std::shared_ptr<TListItem<T>> tmp = this->head;
    for(int32_t i = 0; i < index - 1; ++i) {
        tmp = tmp->GetNext();
    }
    std::shared_ptr<TListItem<T>> removed = tmp->GetNext();
    std::shared_ptr<T> res = removed->GetT();
    std::shared_ptr<TListItem<T>> nextItem = removed->GetNext();
    tmp->SetNext(nextItem);
    nextItem->SetPrev(tmp);
    size--;
    return res;
}

template <class T>
std::shared_ptr<T> TList<T>::PopFirst() {
    if (size == 1) {
        std::shared_ptr<T> res = this->head->GetT();
        head = nullptr;
        tail = nullptr;
        size--;
        return res;
    }
    head = head->GetNext();   
    std::shared_ptr<T> res = head->GetPrev()->GetT();
    head->SetPrev(nullptr);
    size--;
    return res;
}

template <class T>
std::shared_ptr<T> TList<T>::PopLast() {
    if (size == 1) {
        std::shared_ptr<T> res = head->GetT();
        head = nullptr;
        tail = nullptr;
        size--;
        return res;
    }
    tail = tail->GetPrev();
    std::shared_ptr<T> res = head->GetNext()->GetT();
    head->SetNext(nullptr);
    size--;
    return res;
}

template <class T>
TList<T>::~TList() {
    while (head) {
        head->SetPrev(nullptr);
        head = head->GetNext();
    }
    tail = nullptr;
}

template <class T>
std::shared_ptr<TListItem<T>> TList<T>::GetHead() {
    return head;
}

template <class T>
std::shared_ptr<TListItem<T>> TList<T>::GetTail() {
    return tail;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const TList<T>& list) {

    std::shared_ptr<TListItem<T>> item = list.head;
    for(int i = 0; i < list.size; i++) {
      os << "id: " << i + 1 << " ";
      item->GetT()->Print();
      item = item->GetNext();
      os << std::endl;
    }
    os << std::endl;
    return os;
}

#include "Figure.hpp"
template class TList<Figure>;
template std::ostream& operator<<(std::ostream& out, const TList<Figure>& obj);