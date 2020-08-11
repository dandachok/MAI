#include <iostream>
#include <memory>
#include "TQueue.h"

template <class T>
TQueue<T>::TQueue()
{
    head = nullptr;
    count = 0;
}

template <class T>
void TQueue<T>::Push(const T &item)
{
    TQueueItem<T> *tmp = new TQueueItem<T>(item, head);
    head = tmp;
    ++count;
}

template <class T>
bool TQueue<T>::IsEmpty() const
{
    return !count;
}

template <class T>
uint32_t TQueue<T>::GetSize() const
{
    return count;
}

template <class T>
void TQueue<T>::Pop()
{
    if(head) {
        TQueueItem<T> *tmp = &head->GetNext();
        delete head;
        head = tmp;
        --count;
    }
}

template <class T>
T &TQueue<T>::Top()
{
    return head->Pop();
}

template <class T>
TQueue<T>::~TQueue()
{
    for(TQueueItem<T> *tmp = head, *tmp2; tmp; tmp = tmp2) {
        tmp2 = &tmp->GetNext();
        delete tmp;
    }
}

typedef unsigned char Byte;

template class
TQueue<void *>;