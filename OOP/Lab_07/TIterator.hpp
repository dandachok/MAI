#ifndef TITERATOR_HPP
#define TITERATOR_HPP

#include <iostream>

template <class node, class T>
class TIterator {
public:
    TIterator(std::shared_ptr<node> item) {
        node_ptr = item;
    }

    std::shared_ptr<T> operator * () {
        return node_ptr->GetT();
    }

    std::shared_ptr<T> operator -> () {
        return node_ptr->GetT();
    }

    void operator ++ () {
        node_ptr = node_ptr->GetNext();
    }

    TIterator operator ++ (int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator == (const TIterator& i) {
        return node_ptr == i.node_ptr;
    }

    bool operator != (const TIterator& i) {
        return node_ptr != i.node_ptr;
    }
private:
    std::shared_ptr<node> node_ptr;
};

#endif