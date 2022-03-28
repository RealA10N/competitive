#include <bits/stdc++.h>

#include "Hydroplane.h"
using namespace std;

#define fori(n, i) for (int i = 0; i < n; i++)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pq;

const int maxn = 5e5 + 5;  // wrong maxn in statement!
vii g[maxn];

const ll inf = 1e18;
ll sd[maxn], td[maxn];

void dijkstra(int s, ll* d, int n) {
    fori(n, i) d[i] = inf;

    pq q;
    q.push({0, s});

    while (q.size()) {
        ll dd = q.top().first, u = q.top().second;
        q.pop();
        if (d[u] != inf) continue;
        d[u] = dd;
        for (ii p : g[u]) {
            int v = p.first, c = p.second;
            q.push({dd + c, v});
        }
    }
}

ll MinimalCost(int N, int M, int H, int S, int T, vi A, vi B, vi C, vi X,
               vi Y) {
    fori(M, i) g[A[i]].push_back({B[i], C[i]}), g[B[i]].push_back({A[i], C[i]});
    dijkstra(S, sd, N), dijkstra(T, td, N);

    ll mi = sd[T];
    fori(H, i) mi = min(mi, sd[X[i]] + td[Y[i]]);
    return mi;
}
