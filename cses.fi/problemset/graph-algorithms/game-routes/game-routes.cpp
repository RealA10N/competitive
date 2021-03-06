// a10n - Wed Mar 23 11:31:34 2022
// Game Routes (https://cses.fi/problemset/task/1681)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;
vi gt[maxn];
int deg[maxn], paths[maxn];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n, m;
    cin >> n >> m;

    fori(n + 1, i) deg[i] = 0, paths[i] = 0;
    paths[n] = 1;

    fori(m, i) {
        int a, b;
        cin >> a >> b;
        deg[a]++, gt[b].push_back(a);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!deg[i]) q.push(i);

    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : gt[u]) {
            if (--deg[v] == 0) q.push(v);
            paths[v] += paths[u], paths[v] %= MOD;
        }
    }

    cout << paths[1] << endl;
}
