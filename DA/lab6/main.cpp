#include <iostream>
//#include "Big_Integer.hpp"
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>

#define BASE 10000
#define BASE_LENGTH 4

class Big_Integer {
public:
    Big_Integer();
    Big_Integer(std::string s);
    int Get_Digit(const int i) const;
    void Filter_Zeros();

    Big_Integer& operator = (Big_Integer right);
    friend std::ostream& operator << (std::ostream& os, const Big_Integer& item);
    friend std::istream& operator >> (std::istream& is, Big_Integer& item);
    friend bool operator == (const Big_Integer& left, const Big_Integer& right);
    friend bool operator > (const Big_Integer& left, const Big_Integer& right);
    friend bool operator < (const Big_Integer& left, const Big_Integer& right);
    friend Big_Integer operator + (const Big_Integer& left, const Big_Integer& right);
    friend Big_Integer operator - (const Big_Integer& left, const Big_Integer& right);
    friend Big_Integer operator * (const Big_Integer& left, const Big_Integer& right);
    friend Big_Integer operator * (const Big_Integer& left, const int right);
    friend Big_Integer operator ^ (const Big_Integer& val, const Big_Integer& n);
    friend Big_Integer operator / (const Big_Integer& left, const Big_Integer& right);

    std::vector<long int> data;
};

const Big_Integer z("0");
const Big_Integer e("1");
const Big_Integer b("2");

Big_Integer::Big_Integer() {
}

Big_Integer::Big_Integer(std::string s) {
    data.resize(0);
    for(int i = (int)s.length(); i  > 0; i -= BASE_LENGTH) {
        if(i < BASE_LENGTH) {
            data.push_back(atoi(s.substr(0, i).c_str()));
        }
        else {
            data.push_back(atoi(s.substr(i - BASE_LENGTH, BASE_LENGTH).c_str()));
        }
    }
}

std::ostream& operator << (std::ostream& os, const Big_Integer& item) {
    printf("%ld", item.data[item.data.size() - 1]);
    for(int i = (int)item.data.size() - 2; i >= 0; --i) {
        printf("%04ld", item.data[i]);
    }
    os << std::endl;
    return os;
}

std::istream& operator >> (std::istream& is, Big_Integer& item) {
    std::string s;
    item.data.resize(0);
    is >> s;
    for(int i = (int)s.length(); i  > 0; i -= BASE_LENGTH) {
        if(i < BASE_LENGTH) {
            item.data.push_back(atoi(s.substr(0, i).c_str()));
        }
        else {
            item.data.push_back(atoi(s.substr(i - BASE_LENGTH, BASE_LENGTH).c_str()));
        }
    }
    item.Filter_Zeros();
    return is;
}
bool operator == (const Big_Integer& left, const Big_Integer& right) {
    if(left.data.size() != right.data.size()) {
        return false;
    }
    for(size_t i = 0; i < left.data.size(); i++) {
        if(left.data[i] != right.data[i]) {
            return false;
        }
    }
    return true;
}
bool operator > (const Big_Integer& left, const Big_Integer& right) {
    if(left.data.size() != right.data.size()) {
        if(left.data.size() > right.data.size()) {
            return true;
        }
        else {
            return false;
        }
    }
    for(int64_t i = left.data.size() - 1; i >= 0; --i) {
        if(left.data[i] > right.data[i]) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}
bool operator < (const Big_Integer& left, const Big_Integer& right) {
    if(left.data.size() != right.data.size()) {
        if(left.data.size() < right.data.size()) {
            return true;
        }
        else {
            return false;
        }
    }
    for(int64_t i = left.data.size() - 1; i >= 0; --i) {
        if(left.data[i] < right.data[i]) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

int Big_Integer::Get_Digit(const int i) const {
    if(i >= data.size()) {
        return 0;
    }
    return data[i];
}

void Big_Integer::Filter_Zeros() {
    for(int i = data.size() - 1; i >= 1; --i) {
        if(data[i] != 0) {
            break;
        }
        data.pop_back();
    }
}

Big_Integer& Big_Integer::operator = (Big_Integer right) {
    if(*this == right) {
        return *this;
    }
    data.resize(right.data.size());
    for(size_t i = 0; i < data.size(); ++i) {
        data[i] = right.data[i];
    }
    return *this;
}

Big_Integer operator + (const Big_Integer& left, const Big_Integer& right) {
    Big_Integer c;
    c.data.resize(std::max(left.data.size(), right.data.size()));
    int r = 0;
    for(int i = 0; i < c.data.size(); ++i) {
        c.data[i] = left.Get_Digit(i) + right.Get_Digit(i) + r;
        r = c.data[i] / BASE;
        c.data[i] %= BASE;
    }
    if(r > 0) {
        c.data.push_back(r);
    }
    return c;
}

Big_Integer operator - (const Big_Integer& left, const Big_Integer& right) {
    Big_Integer c;
    c.data.resize(left.data.size());    
    int r = 0;
    for(int i = 0; i < c.data.size(); ++i) {
        c.data[i] = left.Get_Digit(i) - right.Get_Digit(i) - r;
        r = 0;
        if(c.data[i]  < 0) {
            c.data[i] += BASE;
            r = 1;
        }
    }
    c.Filter_Zeros();
    return c;
}

Big_Integer operator * (const Big_Integer& left, const Big_Integer& right) {
    Big_Integer c;
    c.data.resize(left.data.size() + right.data.size());    
    for(size_t i = 0; i < c.data.size(); i++) {
        c.data[i] = 0;
    }
    long long r = 0;
    for(int i = 0; i < left.data.size(); ++i) {
        if(left.data[i] == 0) {
            continue;
        }
        for(int j = 0; j < right.data.size(); ++j) {
            c.data[i + j] += left.data[i] * right.data[j];
            r = c.data[i + j] / BASE;
            c.data[i + j + 1] += r;
            c.data[i + j] %= BASE;
        }
        if(r > 0) {
            c.data[i + right.data.size()] = r;
        }
    }
    c.Filter_Zeros();
    return c;
}

Big_Integer operator * (const Big_Integer& left, const int right) {
    Big_Integer r;
    if(right < BASE) {
        r.data.push_back(right);
    }
    else {
        r.data.push_back(right % BASE);
        r.data.push_back(right / BASE);
    }
    return left * r;
}

Big_Integer operator ^ (const Big_Integer& val, const Big_Integer& n) {
    if(n == z) {
        //std::cout << n << "\n";
        return e;
    }
    if(n.data[0] & 1) {
        //std::cout << n << "\n";
        return val * (val ^ (n - e));
    }
    Big_Integer res = (val ^ (n / b));
    //std::cout << res << " ";
    return res * res;
}

Big_Integer operator / (const Big_Integer& left, const Big_Integer& right) {
    Big_Integer u = left, v = right;
    int n = v.data.size(), m = u.data.size() - v.data.size();
    u.data.push_back(0);
    if(n == 1) {
        int q = 0;
        for(int i = u.data.size() - 1; i >= 0; i--) {
            int cur = u.data[i] + q * BASE;
            u.data[i] = (cur / v.data[0]);
            q = (cur % v.data[0]);
        }
        u.Filter_Zeros();
        return u;
    }
    //std::cout << "n = " <<  n  << " m = "<< m << "\n";
    int d = BASE / (v.data[n - 1] + 1);
    //std::cout << u << v << "d = " << d << "\n";
    if (d == 1) {
        u.data[n + m] = 0;
    }
    else {
        u = u * d;
        v = v * d;
    }
    u.data[u.data.size()] = 0;
    //std::cout << u << v;
    Big_Integer res;
    res.data.resize(m + 1, 0);
    //std::cout << u.data[u.data.size()] << '\n';
    for(int j = m; j >=0; --j) {
        //std::cout << "data[" << n + j << "] " << u.data[n + j] << " data[" << n + j - 1<< "] = " << u.data[n + j - 1] << " v.data[" << n - 1 << "] = " << v.data[n - 1] << "\n";
        int q = (u.data[n + j] * BASE + u.data[n + j - 1]) / v.data[n - 1];
        int r = (u.data[n + j] * BASE + u.data[n + j - 1]) % v.data[n - 1];
        //std::cout << "q1 = " << q << " ";
        while((q == BASE) || (q * v.data[n - 2] > BASE * r +u.data[j + n - 2])) {
            q--;
            r += v.data[n - 1];
            if(r >= BASE) {
                break;
            }
        }
        //std::cout << "q2 = " << q << "\n";
        int rr = 0;
        Big_Integer ex_v = v * q;
        //std::cout << u << ex_v;
        for(int i = j; i < u.data.size(); ++i) {
            u.data[i] = u.Get_Digit(i) - ex_v.Get_Digit(i - j) - rr;
            rr = 0;
            if(u.data[i]  < 0) {
                u.data[i] += BASE;
                rr = 1;
            }
        }
        //std::cout << u.data[n + m];
        res.data[j] = q;
        u.Filter_Zeros();
        //std::cout << u << res;
    }
    //std::cout << res;
    res.Filter_Zeros();
    return res;
}

int main() {
    Big_Integer i, j;
    while(std::cin >> i) {
        std::cin >> j;
        char act;
        std::cin >> act;
        switch(act) {
            case 'f':
                while(i > z) {
                    i = i - e;
                    std::cout << i;
                }
                break;
            case '+':
                std::cout << i + j;
                break;
            case '-':
                if(i < j) 
                    std::cout << "Error\n";
                else
                    std::cout << i - j;
                break;
            case '*':
                std::cout << i * j;
                break;
            case '/':
                if(j == z) {
                    std::cout << "Error\n";
                } else if ((i.data[i.data.size() - 1] < 0) || (j.data[j.data.size() - 1] < 0)) {
                    std::cout << "Error\n";
                } else if(i < j) {
                    std::cout << "0\n";
                } else {
                    std::cout << i / j;
                }
                break;
            case '^':
                if(i == z) {
                    if(j == z)
                        std::cout << "Error\n";
                    else
                        std::cout << "0\n";
                }
                else if(i == e){
                    std::cout << "1\n";
                } else {
                    std::cout << (i ^ j);
                }
                break;
            case '>':
                std::cout << ((i > j) ? "true\n": "false\n");
                break;
            case '<':
                std::cout << ((i < j) ? "true\n": "false\n");
                break;
            case '=':
                std::cout << ((i == j) ? "true\n": "false\n");
                break;
        }
    }
    return 0;
}