#ifndef STRING
#define STRING

#include <algorithm>
#include <iostream>
#include <cstring>

#define MAX_SIZE 257

char buf[MAX_SIZE];

class string {
    using value_type = char;
    using iterator = value_type*;
    using const_iterator = const value_type*;

public:
    string() :
        already_used_(0),
        storage_size_(0),
        storage_(nullptr)
        {
        }
    
    string(const string& str) :
        string()
    {
        already_used_ = str.already_used_;
        storage_size_ = str.storage_size_;
        storage_ = new value_type[storage_size_];
        std::copy(str.storage_, str.storage_ + str.storage_size_, storage_);
    }

    string(const value_type* cstr) :
        string()
        {
            int cstr_size = strlen(cstr);

            storage_size_ = 1;
            if(cstr_size) {
                storage_size_ = cstr_size * 2 + 1;
            }

            storage_ = new value_type[storage_size_];
            already_used_ = cstr_size;

            std::copy(cstr, cstr + cstr_size + 1, storage_);
        }

    int size() const
    {
        return already_used_;
    }

    bool empty()
    {
        return already_used_ == 0;
    }

    iterator begin() 
    {
        return storage_;
    }

    iterator end()
    {
        return storage_ + already_used_;
    }

    friend void swap(string& lhs, string& rhs)
    {
        using std::swap;

        swap(lhs.already_used_, rhs.already_used_);
        swap(lhs.storage_size_, rhs.storage_size_);
        swap(lhs.storage_, rhs.storage_);
    }

    string& operator= (const string& str)
    {   
        string next(str);
        swap(*this, next);
        return *this;
    }

    string& operator= (string&& str) noexcept {
        already_used_ = str.already_used_;
        storage_size_ = str.storage_size_;
        storage_ = str.storage_;
        std::cout << "move copy\n";
        return *this;
    }

    string& operator= (const value_type* cstr)
    {
        string next(cstr);
        swap(*this, next);
        return *this;
    }

    const value_type& at(int idx) const
    {
        if(idx < 0 || idx > already_used_)
            throw std::out_of_range("You are doing this wrong");
        return storage_[idx];
    }

    value_type& at(int idx)
    {
        const value_type& elem = const_cast<const string*>(this)->at(idx);
        return const_cast<value_type&>(elem);
    }

    const value_type& operator[] (int idx) const
    {
        return at(idx);
    }

    value_type& operator[] (int idx)
    {
        return at(idx);
    }

    value_type* cstr() {
        return storage_;
    }

    friend std::istream& operator>> (std::istream& is, string& str)
    {
        is >> buf;
        str = buf;
        return is;
    }

    friend std::ostream& operator<< (std::ostream& os, const string& str)
    {
        os << str.storage_;
        return os;
    }

    bool digit(int idx) 
    {
        size_t char_num = idx / 8;
        if (char_num >= already_used_) return 0; 
        size_t bit_num = idx % 8;
        return storage_[char_num] & (1 << (7 - bit_num));
    }

    ~string()
    {
        delete[] storage_;

        already_used_ = 0;
        storage_size_ = 0;
        storage_ = nullptr;
    }
private:
    int already_used_;
    int storage_size_;
    value_type* storage_;
};

bool operator< (const string& rhs, const string& lhs)
    {
        int min_size = std::min(lhs.size(), rhs.size());
        for(int i = 0; i < min_size; ++i) {
            if(lhs[i] == rhs[i]) {
                continue;
            } else {
                return lhs[i] < rhs[i];
            }
        }
        return lhs.size() < rhs.size();
    }

bool operator> (const string& lhs, const string& rhs)
{
    return lhs < rhs;
}

bool operator== (const string& lhs, const string& rhs)
{
    return !(lhs < rhs) && !(rhs < lhs);
}

#endif