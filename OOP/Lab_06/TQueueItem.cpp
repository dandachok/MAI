#include "TQueueItem.hpp"

template <class T>
TQueueItem<T>::TQueueItem(T& item) : next(nullptr), value(item) {
}

template <class T>
void TQueueItem<T>::SetNext(TQueueItem<T>* item) {
    next = item;
}

template <class T>
TQueueItem<T>* TQueueItem<T>::GetNext() {
    return next;
}

template <class T>
T TQueueItem<T>::GetValue() {
    return value;
}

template class TQueueItem<void *>;