#include <bits/stdc++.h>

#include "Ammunition.h"
using namespace std;

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)

int n, q, blksz, blkamt;

const int maxn = 2e5 + 5;
const int maxsqrtn = 500;
int full[maxn];
int blocks[maxsqrtn][maxsqrtn];

void init(signed N, signed Q) {
    n = N, q = Q, blksz = ceil(sqrt(n));
    for (int i = 0; i <= N; i++) full[i] = 0;
    fori(maxsqrtn, i) fori(maxsqrtn, j) blocks[i][j] = 0;
}

void aid(signed A, signed B, signed C) {
    if (B > blksz) {
        for (int k = A; k <= n; k += B) full[k] += C;
    } else {
        blocks[B][A] += C;
    }
}

signed check(signed D) {
    int ans = full[D];
    for (int b = 1; b <= blksz; b++) {
        ans += blocks[b][D % b];
    }
    return ans;
}
