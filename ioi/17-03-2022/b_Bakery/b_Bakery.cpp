#include <bits/stdc++.h>
using namespace std;
#include "bakery.h"

typedef long long ll;
typedef vector<ll> vll;
#define fori(n, i) for (int i = 0; i < n; i++)
#define blksz(i) (i & -i)

const ll maxn = 1e5 + 5;
int n, fw[maxn];
ll ans[maxn];

inline void update(int i, int v) {
    while (i <= n) fw[i] += v, i += blksz(i);
}

inline int get(int i) {
    int v = 0;
    while (i > 0) v += fw[i], i -= blksz(i);
    return v;
}

void ProblemLaPastry(int N, vll A) {
    n = N;
    fori(n + 1, i) fw[i] = ans[i] = 0;
    fori(n, i) {
        ll fwi = A[i] + 1;
        if (fwi < maxn) ans[fwi] += i - get(fwi), update(fwi, 1);
    }
    ll v = 0;
    fori(n, i) Inv(v += ans[i]);
}
