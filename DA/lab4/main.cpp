#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>

int in(unsigned int& c, int& n, int& string_num, int& char_num, std::queue<int>& strings, std::queue<int>& chars) {
    std::string str;
    char ch = 0;
    while(1) {
        ch = std::cin.get();
        if(ch >= '0' && ch <= '9') {
            str.push_back(ch);
            break;
        }
        if(ch == '\n') {
            string_num++;
            char_num = 0;
        }
        if(ch == EOF) return 2;
    }
    while(1) {
        std::cin.get(ch);
        if(ch >= '0' && ch <= '9') {
            str.push_back(ch);
        } else {
            c = atoi(str.c_str());
            char_num++;
            strings.push(string_num);
            chars.push(char_num);
            if(strings.size() > n + 1) {
                strings.pop();
            }
            if(chars.size() > n + 1) {
                chars.pop();
            }
            if(ch == '\n') {
                string_num++;
                char_num = 0;
            }
            if(ch == EOF) return 1;
            break;
        }
    }
    return 0;
}

void KMP(std::vector<unsigned int>& p) {
    int n = p.size();
    std::queue<int> strings;
    std::queue<int> chars;
    std::vector<int> sp(n, 0);
    for(int i = 1; i < n; i++) {
        int j = sp[i - 1];
        while(j > 0 && p[i] != p[j]) {
            j = sp[j - 1];
        }
        if(p[j] == p[i]) {
            j++;
        }
        sp[i] = j;
    }
    unsigned int c = 0;
    std::string str;
    int i = 0;
    int string_num = 1, char_num = 0;
    bool flag = false;
    int f = 0;
    f = in(c, n, string_num, char_num, strings, chars);
    if(f == 2) return;
    if(f == 1) {
        if(p.size() == 1 && p[0] == c) {
            std::cout << "1, 1\n";
            return;
        } else {
            return;
        }
    }
    while(1) {
        if(flag) break;
        while(i < n && c == p[i]) {
            i++;
            f = in(c, n, string_num, char_num, strings, chars);
            if(f == 1) return;
            if(f == 2) {
                flag = true;
                break;
            }
        }
        if(i == n) {
            if(flag == true && strings.size() != 1) {
                strings.pop();
                chars.pop();
            }
            std::cout << strings.front() << ", " << chars.front() << '\n';
        }
        if(i == 0) {
            if(flag) break;
            f = in(c, n, string_num, char_num, strings, chars);
            if(f == 1) return;
            if(f == 2) {
                flag = true;
                break;
            }
        }
        if(i != 0) i = sp[i - 1];
    }
}//
//
void fun(std::vector<unsigned int>& p) {
    std::cout << p[1] << '\n';
}

int main() {
    std::vector<unsigned int> p(0);
    unsigned int val = 0;
    std::string s;
    getline(std::cin, s);
    std::stringstream ss(s);
    while(ss >> val) {
        p.push_back(val);
    }

    KMP(p);
    return 0;
}