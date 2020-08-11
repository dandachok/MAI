#pragma once

#include <algorithm>
#include "string.hpp"

template <typename T1, typename T2>
class pair {
    using key_type = T1;
    using value_type = T2;
public:
    pair() :
        key(),
        value()
    {
    }
    pair(const key_type& k, const value_type& v) :
        key(k),
        value(v)
    {
    }

    friend void swap(pair& lhs, pair& rhs)
    {
        // using std::swap;
        std::swap(lhs.key, rhs.key);
        swap(lhs.value, rhs.value);
    }

    const key_type& get_key() const
    {
        return key;
    }

    key_type& get_key()
    {
        const key_type& elem = const_cast<const pair*>(this)->get_key();
        return const_cast<key_type&>(elem);
    }

    void set_key(const key_type& k)
    {
        key = k;
    }

    const value_type& get_value() const
    {
        return value;
    }

    value_type& get_value()
    {
        const value_type& elem = const_cast<const pair*>(this)->get_value();
        return const_cast<value_type&>(elem);
    }

    void set_value(const value_type& v)
    {
        value = v;
    }

    ~pair()
    {
    }
private:
    key_type key;
    value_type value;
};