#include <bits/stdc++.h>

#include "Ducks.h"
using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define fori(n, i) for (ll i = 0; i < n; i++)
const double eps = 1e-7;

inline ll endpoint(double x) {
    if (abs(round(x) - x) <= eps) return round(x);
    return ceil(x);
}

inline ll startpoint(double x) {
    if (abs(round(x) - x) <= eps) return round(x) + 1;
    return ceil(x);
}

void Hide(int N, int L, int R, int Y, vi x, vi v, vi h) {
    map<ll, ll> map;
    fori(N, i) {
        double m = (double)v[i] / h[i], dx = Y / m;
        map[startpoint(x[i] - dx)]++, map[endpoint(x[i] + dx)]--;
    }

    vector<ll> a(N + 1);
    ll k = 0;
    bool seenend = false;
    for (auto p : map) {
        ll x = p.first;
        if (x > R) seenend = true, x = R + 1;
        if (L <= x) a[k] += x - L, L = x;
        k += p.second;
        if (seenend) break;
    }

    a[k] += R - L + 1, k = 0;
    fori(N + 1, i) ans(k += a[i]);
}
