#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;

void dfs(vvi &paths, vvi &g, int u, int parpath = -1) {
    if (parpath == -1) {
        parpath = sz(paths);
        paths.emplace_back();
    }
    paths[parpath].push_back(u);
    if (g[u].size()) dfs(paths, g, g[u][0], parpath);
    for (int i = 1; i < sz(g[u]); i++) dfs(paths, g, g[u][i]);
}

void solve() {
    vvi paths;
    int n;
    cin >> n;
    vvi g(n);
    int root;
    fori(n, i) {
        int a;
        cin >> a;
        a--;
        if (a == i)
            root = i;
        else
            g[a].push_back(i);
    }

    dfs(paths, g, root);

    cout << paths.size() << endl;
    for (vi &p : paths) {
        cout << p.size() << endl;
        for (int u : p) cout << (u + 1) << ' ';
        cout << endl;
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}
