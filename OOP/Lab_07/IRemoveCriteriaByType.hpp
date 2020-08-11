#ifndef IREMOVECRITERIABYTYPE_H
#define IREMOVECRITERIABYTYPE_H
#include "IRemoveCriteria.hpp"


template <class T> class IRemoveCriteriaByType : public IRemoveCriteria<T>
{
  public:
    IRemoveCriteriaByType(int type) : Type(type) {};
    bool isIt(T* figure) override {
      return figure->GetType() == Type;
    }
  private:
    int Type;
};

#endif // IREMOVECRITERIABYTYPE_H
