#include "TQueueItem.hpp"

template <class T>
TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& obj){
    this->item = obj;
    this->next = nullptr;
}

template <class T> TAllocationBlock
TQueueItem<T>::queueitem_allocator(sizeof(TQueueItem<T>), 100);

template <class T>
std::shared_ptr<T> TQueueItem<T>::GetT(){
    return item;
}

template <class T>
std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext(){
    return next;
}

template <class T>
void TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> item){
    this->next = item;
}

template <class T>
std::ostream& operator<<(std::ostream &os, const TQueueItem<T> &obj){
    os << "(" << obj.item << ")";
    return os;
}

template <class T>
void* TQueueItem<T>::operator new(size_t size) {
    return queueitem_allocator.allocate();
}

template <class T>
void TQueueItem<T>::operator delete(void* pointer) {
    return queueitem_allocator.deallocate(pointer);
}

#include "Figure.hpp"
template class TQueueItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure>& obj);