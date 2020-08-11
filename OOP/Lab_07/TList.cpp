#include "TList.hpp"

template <class T, class TT>
TList<T,TT>::TList() {
    head = nullptr;
    size = 0;
}

template <class T, class TT>
size_t TList<T, TT>::GetSize() {
    return this->size;
}

template <class T, class TT>
bool TList<T, TT>::IsEmpty() {
    return head == nullptr;
}

template <class T, class TT>
void TList<T, TT>::InsertSubitem(std::shared_ptr<TT>& value) {
    bool flag = false;
    if (head != nullptr) {
        for (auto i : * this) {
            if (i->GetSize() < 5) {
                i->Push(value);
                std::cout << "List: Add Element in list:" << i->GetSize() << std::endl;
                flag = true;
            }
        }
    }
    if(!flag) {
        std::cout << "List: New list element created" << std::endl;
        std::shared_ptr<T> t_value = std::make_shared<T>();
        t_value->Push(value);
        PushLast(t_value);
    }
}

template<class T, class TT>
void TList<T, TT>::RemoveSubitem(IRemoveCriteria<TT> &criteria) {
    for(auto i: *this) {
        T copy;
        while(!i->IsEmpty()) {
            std::shared_ptr<TT> value = i->Pop();
            if(criteria.isIt(&*value)) {
                std::cout << "List: Delete figure";
                value->Print();
            }
            else{
                std::cout << "Push" << std::endl;
                copy.Push(value);
            }
        }
        while (!copy.IsEmpty()) {
            std::shared_ptr<TT> obj = copy.Pop();
            i->Push(obj);
        }
    }
}

template <class T, class TT>
void TList<T, TT>::PushIndex(size_t index, std::shared_ptr<T>& obj) {
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

template <class T, class TT>
void TList<T, TT>::PushLast(std::shared_ptr<T>& obj) {
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

template <class T, class TT>
void TList<T, TT>::PushFirst(std::shared_ptr<T> &obj) {
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

template <class T, class TT>
std::shared_ptr<T> TList<T, TT>::PopIndex(size_t index) {
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

template <class T, class TT>
std::shared_ptr<T> TList<T, TT>::PopFirst() {
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

template <class T, class TT>
std::shared_ptr<T> TList<T, TT>::PopLast() {
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

template <class T, class TT>
TList<T, TT>::~TList() {
    while (head) {
        head->SetPrev(nullptr);
        head = head->GetNext();
    }
    tail = nullptr;
}

template <class T, class TT>
std::shared_ptr<TListItem<T>> TList<T, TT>::GetHead() {
    return head;
}

template <class T, class TT>
std::shared_ptr<TListItem<T>> TList<T, TT>::GetTail() {
    return tail;
}

template <class T, class TT>
TIterator<TListItem<T>, T> TList<T, TT>::begin() const {
    return TIterator<TListItem<T>, T> (head);
}

template <class T, class TT>
TIterator<TListItem<T>, T> TList<T, TT>::end() const{
    return TIterator<TListItem<T>, T> (nullptr);
}

template <class T, class TT>
std::ostream& operator<<(std::ostream& os, const TList<T, TT>& list) {
    for(auto i: list) {
      os << "List element:" << std::endl << *i;
    }
    os << std::endl;
    return os;
}

#include "Figure.hpp"
#include "TQueue.hpp"
template class TList<TQueue<Figure>,Figure>;
template std::ostream& operator<<(std::ostream& out, const TList<TQueue<Figure>,Figure>& obj);