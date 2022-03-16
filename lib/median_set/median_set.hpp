#pragma once
#include <set>
using namespace std;

template <typename T>
struct median_set {
    multiset<T> lo, hi;
    T median() { return balance(), *hi.begin(); }
    size_t count(T v) { return lo.count(v) + hi.count(v); }

    void balance() {
        while (hi.size() > lo.size()) {
            auto t = hi.begin();
            lo.insert(*t), hi.erase(t);
        }

        while (lo.size() > hi.size()) {
            auto t = lo.rbegin();
            hi.insert(*t), lo.erase(lo.find(*t));
        }
    };

    void insert(T v) {
        if (v >= *hi.begin())
            hi.insert(v);
        else
            lo.insert(v);
    }

    bool erase(T v) {
        auto t = lo.find(v);
        if (t != lo.end())
            return lo.erase(t), true;
        else {
            t = hi.find(v);
            if (t != hi.end()) return hi.erase(t), true;
        }
        return false;
    }
};
