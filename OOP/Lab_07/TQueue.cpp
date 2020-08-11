#include "TQueue.hpp"

template <class T>
TQueue<T>::TQueue() {
    head = nullptr;
    size = 0;
}

template <class T>
size_t TQueue<T>::GetSize() {
    return this->size;
}

template <class T>
bool TQueue<T>::IsEmpty() {
    return head == nullptr;
}

template <class T>
void TQueue<T>::Push(std::shared_ptr<T> &obj) {
    std::shared_ptr<TQueueItem<T>> item = std::make_shared<TQueueItem<T>>(obj);
    if(size == 0) {
        head = item;
        tail = item;
    }
    else if(head->GetT()->Square() > item->GetT()->Square()) {
        item->SetNext(head);
        head = item;
    }
    else{
        for(std::shared_ptr<TQueueItem<T>> j = head; j != nullptr; j = j->GetNext()) {
            if(j->GetNext() == nullptr) {
                j->SetNext(item);
                tail = item;
                break;
            }
            if(j->GetT()->Square() < item->GetT()->Square() && j->GetNext()->GetT()->Square() > item->GetT()->Square()) {
                item->SetNext(j->GetNext());
                j->SetNext(item);
                break;
            }
        }
    }
    size++;
}

template <class T>
std::shared_ptr<T> TQueue<T>::Pop() {
    if (size == 1) {
        std::shared_ptr<T> res = head->GetT();
        head = nullptr;
        tail = nullptr;
        size--;
        return res;
    }
    std::shared_ptr<T> res = head->GetT();
    head = head->GetNext();
    size--;
    return res;
}

template <class T>
TQueue<T>::~TQueue() {
    while (head) {
        Pop();
    }
}

template <class T>
TIterator<TQueueItem<T>, T> TQueue<T>::begin() {
    return TIterator<TQueueItem<T>, T> (head);
}

template <class T>
TIterator<TQueueItem<T>, T> TQueue<T>::end() {
    return TIterator<TQueueItem<T>, T> (nullptr);
}

template <class T>
std::ostream& operator<<(std::ostream& os, TQueue<T>& queue) {
    for(auto i: queue) {
        i->Print();
    }
    os << std::endl;
    return os;
}

#include "Figure.hpp"
template class TQueue<Figure>;
template std::ostream& operator<<(std::ostream& out, TQueue<Figure>& obj);