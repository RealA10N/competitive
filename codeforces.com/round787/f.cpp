#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
typedef vector<int> vi;
typedef set<int> si;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<vi> vvi;

int dfs(int u, int f, si& items, vvi& g) {
    int moves = 0;
    for (int v : g[u]) {
        if (v == f) continue;
        int extra = dfs(v, u, items, g);
        if (extra || items.count(v)) moves += extra + 2;
    }
    return moves;
}

int pathlen(int u, int t, vvi& g, int f) {
    if (u == t) return 0;
    for (int v : g[u]) {
        if (v == f) continue;
        int l = pathlen(v, t, g, u);
        if (l != -1) return l + 1;
    }

    return -1;
}

void solve() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    si items;
    fori(k, i) {
        int a;
        cin >> a;
        items.insert(a);
    }
    items.insert(y);

    vvi g(n + 1);
    fori(n - 1, i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }

    cout << dfs(x, 0, items, g) - pathlen(x, y, g, 0) << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}
