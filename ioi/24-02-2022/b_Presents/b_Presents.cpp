#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
vector<long long> g[maxn];

long long LastDay(int N, int F, int S, int T, vector<int> A, vector<int> B) {
#define int long long

    vector<int> prev(N, 0), cur(N, 0);
    cur[S] = 1;

    for (int i = 0; i < F; i++) {
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }

    while (T--) {
        prev = cur;
        fill(cur.begin(), cur.end(), 0);
        for (int i = 0; i < N; i++) {
            for (int u : g[i]) cur[i] += prev[u];
        }
    }

    int s = 0;
    for (int v : cur) s += v;
    return s;
}
