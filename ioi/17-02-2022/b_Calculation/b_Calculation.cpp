#include <bits/stdc++.h>
using namespace std;

signed calculate(string F) {
    if (F.size() < 9) {
        int a = stoi(F), sz = 1;
        while (a > 1) sz++, a /= sz;
        return sz;
    }

    int n = 1, target = F.size() - 1;
    double sz = 0;
    while (sz < target) sz += log10(++n);
    return n;
}
