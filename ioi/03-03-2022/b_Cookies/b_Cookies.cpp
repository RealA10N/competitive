#include <bits/stdc++.h>

#include "Cookies.h"
using namespace std;

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<bool> vb;

const int maxn = 2e5 + 5;
const int maxlogn = 20;
vi g[maxn];

int heights[maxn], ins[maxn], outs[maxn], k[maxn][maxlogn];
int T = 0;

void dfs(int u, int from, int h) {
    heights[u] = h, ins[u] = T++, k[u][0] = from;

    for (int ki = 1, hd = 2; hd <= h; ki++, hd *= 2)
        k[u][ki] = k[k[u][ki - 1]][ki - 1];

    for (int v : g[u])
        if (heights[v] == -1) dfs(v, u, h + 1);

    outs[u] = T++;
}

#define ancestor(p, c) (p == c || (ins[p] < ins[c] && outs[p] > outs[c]))

int lca(int a, int b) {
    if (ancestor(a, b)) return a;
    if (ancestor(b, a)) return b;

    for (int ki = maxlogn - 1; ki >= 0; ki--)
        if (!ancestor(k[b][ki], a)) b = k[b][ki];

    return k[b][0];
}

int Cookies(signed N, vector<signed> A, vector<signed> B) {
    fori(N - 1, i) g[A[i]].push_back(B[i]), g[B[i]].push_back(A[i]);

    fori(maxn, i) heights[i] = -1;
    fori(maxn, i) fori(maxlogn, j) k[i][j] = 1;
    dfs(1, -1, 0);

    int ans = 0;
    for (int i = 1; i < N; i++)
        for (int j = 2; i * j <= N; j++)
            ans +=
                heights[i] + heights[i * j] - (2 * heights[lca(i, i * j)]) + 1;

    return ans;
}
