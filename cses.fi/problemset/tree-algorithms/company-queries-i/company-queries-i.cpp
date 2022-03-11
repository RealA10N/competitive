// a10n - Sat Mar  5 11:56:14 2022
// Company Queries I (https://cses.fi/problemset/task/1687)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

// clang-format off
void solution();
#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)
#define cases int _t = 1; cin >> _t; while(_t--)
#define solution() signed main() { cin.tie(NULL)->sync_with_stdio(false); \
    cout<<fixed<<setprecision(10); solution(); } void solution()
// clang-format on

typedef vector<int> vi;
const int maxn = 2e5 + 5;
const int maxlogn = 20;
vi g[maxn];
int s[maxn][maxlogn];

void dfs(int u, int f) {
    s[u][0] = f;
    for (int k = 1; k < maxlogn; k++) s[u][k] = s[s[u][k - 1]][k - 1];
    for (int v : g[u]) dfs(v, u);
}

solution() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        g[a].push_back(i);
    }

    g[0].push_back(1);
    dfs(0, 0);

    while (q--) {
        int a, k;
        cin >> a >> k;
        for (int i = 1, di = 2; i < maxlogn; i++, di *= 2) {
            if (k % di) k -= (di / 2), a = s[a][i - 1];
        }
        cout << (a ? a : -1) << endl;
    }
}