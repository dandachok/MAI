#include "TQueue.hpp"

template <class T>
TQueue<T>::TQueue() : head(nullptr), tail(nullptr), size(0) {
}

template <class T>
bool TQueue<T>::IsEmpty() {
    return size == 0;
}

template <class T>
size_t TQueue<T>::Size() {
    return size;
}

template <class T>
void TQueue<T>::Push(T& item) {
    TQueueItem<T>* new_item = new TQueueItem<T>(item);
    if(IsEmpty()) {
        head = new_item;
        tail = new_item;
        size++;
    }
    else {
        tail->SetNext(new_item);
        tail = new_item;
    }
    size++;
}

template <class T>
T TQueue<T>::Pop() {
    T res = head->GetValue();
    TQueueItem<T>* old_head = head;
    if(Size() == 1) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->GetNext();
    }
    delete old_head;
    size--;
    return res;
}

template <class T>
TQueue<T>::~TQueue() {
    while(!IsEmpty()) {
        Pop();
    }
    head = nullptr;
    tail = nullptr;
}

template class TQueue<void *>;