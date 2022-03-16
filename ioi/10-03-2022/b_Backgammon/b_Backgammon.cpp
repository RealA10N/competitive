#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

#define fori(n, i) for (int i = 0; i < n; i++)

const int maxn = 1e5 + 5;
vi g[maxn];
ll e[maxn], ste[maxn], moves = 0;

void dfs(int u, int f) {
    ste[u] = e[u];
    for (int v : g[u]) {
        if (v == f) continue;
        dfs(v, u);
        ste[u] += ste[v];
        moves += abs(ste[v]);
    }
}

int Backgammon(int N, vi V, vi M, vi D, vi G) {
    int j = 0;
    fori(N, i) {
        e[V[i]] = M[i] - 1;
        fori(D[i], ji) g[V[i]].push_back(G[j]), g[G[j++]].push_back(V[i]);
    }
    return dfs(1, 0), moves;
}
