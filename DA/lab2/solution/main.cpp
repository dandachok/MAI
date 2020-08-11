#include <iostream>
#include <fstream>
#include "PatriciaTree.hpp"

using ull = unsigned long long;

void insert(PatriciaTree& pt) {
    string key;
    ull value = 0;

    std::cin >> key >> value;
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);

    if(pt.find(key, value)) {
        std::cout << "Exist\n";
    } else {
        pt.insert(key, value);
        std::cout << "OK\n";
    }
}

void remove(PatriciaTree& pt) {
    string key;
    ull value = 0;

    std::cin >> key;
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);

    if(!pt.find(key, value)){
        std::cout << "NoSuchWord\n";
    } else {
        pt.remove(key);
        std::cout << "OK\n";
    }
}

void save_load(PatriciaTree& pt) {
    string cmd;
    string file_name;

    std::cin >> cmd >> file_name;
    if(cmd[0] == 'S') {
        pt.fwrite(file_name);
    } else {
        pt.fread(file_name);
    }

    std::cout << "OK\n";
}

void check(PatriciaTree& pt, string& raw_key) {
    string key(raw_key);
    ull value = 0;

    std::transform(key.begin(), key.end(), key.begin(), ::tolower);

    if(!pt.find(key, value)) {
        std::cout << "NoSuchWord\n";
    } else {
        std::cout << "OK: " << value << '\n'; 
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string cmd;
    PatriciaTree pt;
    while(std::cin >> cmd) {
        switch(cmd[0]) {
            case '+' :
                insert(pt);
                break;
            case '-' :
                remove(pt);
                break;
            case '!' :
                save_load(pt);
                break;
            default :
                check(pt, cmd);
                break;
        }
    }
    return 0;
}
