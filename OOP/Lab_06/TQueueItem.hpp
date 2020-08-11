#ifndef TQUEUEITEM_HPP
#define TQUEUEITEM_HPP

template <class T>
class TQueueItem{
public:
    TQueueItem(T& item);
    
    void SetNext(TQueueItem<T>* item);
    TQueueItem<T>* GetNext();
    T GetValue();

    ~TQueueItem() {};
private:
    TQueueItem<T>* next;
    T value;
};

#endif