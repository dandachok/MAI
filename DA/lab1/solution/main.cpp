#include <algorithm>
#include <iostream>
#include "vector.hpp"
#include <utility>
#include "string.hpp"
#include "pair.hpp"

#define MIN_KEY_VALUE -100
#define MAX_KEY_VALUE 100
#define EFFECT 1

void backet_sort(vector<pair<double, string> >& vec) {
    int vector_size = vec.size();
    int count_backets = vector_size / EFFECT;
    int change = (-1) * MIN_KEY_VALUE;
    int dif = MAX_KEY_VALUE - MIN_KEY_VALUE;
    vector<vector<pair<double, string> > > backets(count_backets + 1);
    for(auto i: vec) {
        double sup = (double)count_backets / dif;
        //std::cout << "count:" << count_backets << " dif:" << dif << " new idx:" << int((i.get_key() + change) * sup) << '\n';
        backets[int((i.get_key() + change) * sup)].push_back(i);
    }
    for(auto& i: backets) {
        for(int j = 1; j < i.size(); ++j) {
            int c = j;
            while(c >= 1 && i[c - 1].get_key() > i[c].get_key()) {
                swap(i[c - 1], i[c]);
                --c;
            }
        }
        //for(auto j: i) {
        //    std::cout << j.get_key() << '\t' << j.get_value() << '\n';
        //}
    }
    for(auto i: backets) {
       for(auto j: i) {
           std::cout << j.get_key() << '\t' << j.get_value() << '\n';
       }
    }
}

int main() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    double k;
    string v;
    int dif = 200;
    int change = 100;
    int count_backets = 5000000;
    vector<vector<pair<double, string> > > backets(count_backets + 1);
    while(std::cin >> k >> v) {
        double sup = (double)count_backets / dif;
        //std::cout << "count:" << count_backets << " dif:" << dif << " new idx:" << int((i.get_key() + change) * sup) << '\n';
        backets[int((k + change) * sup)].push_back(pair<double, string>(k, v));
    }
    for(auto& i: backets) {
        for(int j = 1; j < i.size(); ++j) {
            int c = j;
            while(c >= 1 && i[c - 1].get_key() > i[c].get_key()) {
                swap(i[c - 1], i[c]);
                --c;
            }
        }
        //for(auto j: i) {
        //    std::cout << j.get_key() << '\t' << j.get_value() << '\n';
        //}
    }
    for(auto i: backets) {
       for(auto j: i) {
           std::cout << j.get_key() << '\t' << j.get_value() << '\n';
       }
    }
    //vector<pair<double, string> > vec;
    //while(std::cin >> k >> v)
    //{
    //    vec.push_back(pair<double, string>(k, v));
    //}

    //for(auto i: vec) {
    //    std::cout << i.get_key() << '\t' << i.get_value() << '\n';
    //}
    //backet_sort(vec);
    return 0;
}