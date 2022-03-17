#include <bits/stdc++.h>

#include "Magician.h"
using namespace std;

const int maxc = 1e5 + 5;
const int maxr = 1e5 + 5;
const int fwsz = maxr + maxc;
int m[maxc], top;
int fw[fwsz];

#define fori(n, i) for (int i = 0; i < n; i++)
#define blksz(i) (i & -i)

inline void add(int i, int v) {
    while (i < fwsz) fw[i] += v, i += blksz(i);
}

inline int get(int i) {
    int v = 0;
    while (i > 0) v += fw[i], i -= blksz(i);
    return v;
}

void PrepareTheMagic(int C, int R) {
    top = maxr;
    fori(fwsz, i) fw[i] = 0;
    for (int i = 1; i <= C; i++) m[i] = maxr + i, add(maxr + i, 1);
}

int DoTheMagic(int X) {
    int key = m[X];
    int ans = get(key) - 1;
    m[X] = --top;
    add(key, -1), add(top, 1);
    return ans;
}
