// a10n - Fri Mar 11 20:57:19 2022
// Tree Distances II (https://cses.fi/problemset/task/1133)
// Generated by cptk

// clang-format off
#include <bits/stdc++.h>
using namespace std;
void _main();
#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)
#define main signed main() { cin.tie(NULL)->sync_with_stdio(false); \
    cout<<fixed<<setprecision(10); _main(); } void _main()
typedef vector<int> vi;
// clang-format on

const int maxn = 2e5 + 5;
vi g[maxn];
int n, sizes[maxn], ans[maxn];

void calcsizes(int u = 1, int f = 0) {
    sizes[u] = 1;
    for (int v : g[u])
        if (v != f) calcsizes(v, u), sizes[u] += sizes[v];
}

int distsum(int u, int f = 0) {
    int s = 0;
    for (int v : g[u])
        if (v != f) s += sizes[v] + distsum(v, u);
    return s;
}

void calcans(int u, int d, int f = 0) {
    ans[u] = d;
    for (int v : g[u]) {
        if (v == f) continue;
        calcans(v, d + n - 2 * sizes[v], u);
    }
}

main {
    cin >> n;
    fori(n - 1, i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }

    calcsizes(), calcans(1, distsum(1));
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
}