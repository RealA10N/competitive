// a10n - Fri Apr 15 23:40:31 2022
// Investigation (https://cses.fi/problemset/task/1202)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii>> pq;

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;
const int oo = 1e18;
int dist[maxn], ways[maxn], minf[maxn], maxf[maxn];
vi g[maxn];

typedef struct edge {
    int a, b, c;
    edge(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c){};
} edge;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    fori(maxn, i) dist[i] = oo;

    int n, m;
    cin >> n >> m;

    vector<edge> edges;

    fori(m, i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(edges.size());
        edges.emplace_back(a, b, c);
    }

    pq pq;  // {dist, edge}
    pq.push({0, edges.size()});
    edges.emplace_back(0, 1, 0);

    dist[0] = 0;
    minf[0] = maxf[0] = -1;
    ways[0] = 1;

    while (pq.size()) {
        int d, i;
        tie(d, i) = pq.top();
        edge &e = edges[i];
        pq.pop();

        if (dist[e.a] + e.c < dist[e.b]) {
            dist[e.b] = dist[e.a] + e.c;
            ways[e.b] = ways[e.a];
            minf[e.b] = minf[e.a] + 1;
            maxf[e.b] = maxf[e.a] + 1;
            for (int i : g[e.b]) pq.push({dist[e.b] + edges[i].c, i});
        } else if (dist[e.a] + e.c == dist[e.b]) {
            ways[e.b] += ways[e.a], ways[e.b] %= MOD;
            minf[e.b] = min(minf[e.b], minf[e.a] + 1);
            maxf[e.b] = max(maxf[e.b], maxf[e.a] + 1);
        }
    }

    cout << dist[n] << ' ' << ways[n] << ' ' << minf[n] << ' ' << maxf[n]
         << endl;
}