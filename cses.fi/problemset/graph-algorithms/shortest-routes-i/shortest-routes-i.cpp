// a10n - Wed Mar 23 13:05:22 2022
// Shortest Routes I (https://cses.fi/problemset/task/1671/)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxn = 1e5 + 5, inf = 1e18;
vii g[maxn];
int dist[maxn];
bitset<maxn> mark;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    fori(m, i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    fori(n + 1, i) dist[i] = inf, mark[i] = false;
    priority_queue<ii, vii, greater<ii>> q;
    q.push({dist[1] = 0, 1});

    while (q.size()) {
        int d, u;
        tie(d, u) = q.top();
        q.pop();
        if (mark[u]) continue;
        mark[u] = true;
        for (ii& p : g[u]) {
            int v, c;
            tie(v, c) = p;
            if (!mark[v] && dist[u] + c < dist[v])
                q.push({dist[v] = dist[u] + c, v});
        }
    }

    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
    cout << endl;
}