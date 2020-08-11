#include "TListItem.hpp"

template <class T>
TListItem<T>::TListItem(const std::shared_ptr<T>& obj){
    this->item = obj;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T> TAllocationBlock
TListItem<T>::listitem_allocator(sizeof(TListItem<T>), 100);

template <class T>
std::shared_ptr<T> TListItem<T>::GetT(){
    return item;
}

template <class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetNext(){
    return next;
}

template <class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetPrev(){
    return prev;
}

template <class T>
void TListItem<T>::SetNext(std::shared_ptr<TListItem<T>> item){
    this->next = item;
}

template <class T>
void TListItem<T>::SetPrev(std::shared_ptr<TListItem<T>> item){
    this->prev = item;
}

template <class T>
std::ostream& operator<<(std::ostream &os, const TListItem<T> &obj){
    os << "(" << obj.item << ")";
    return os;
}

template <class T>
void* TListItem<T>::operator new(size_t size) {
    return listitem_allocator.allocate();
}

template <class T>
void TListItem<T>::operator delete(void* pointer) {
    return listitem_allocator.deallocate(pointer);
}

#include "Figure.hpp"
template class TListItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TListItem<Figure>& obj);