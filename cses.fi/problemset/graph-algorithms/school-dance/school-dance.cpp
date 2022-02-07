// a10n - Mon Feb  7 11:37:11 2022
// School Dance (https://cses.fi/problemset/task/1696)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

struct flow {
    vvi g, c;
    int n, s, t, curf = 0;
    const int BIG = 1LL << 60;

    flow(int n, int s, int t)
        : g(n + 2, vi()), c(n + 2, vi(n + 2, 0)), n(n), s(s), t(t) {
        // We use node ss=n as the dummy source and tt=n+1 as the dummy sink.
        ss = n, tt = n + 1;
        g[ss].push_back(s), g[t].push_back(tt);
        c[ss][s] = BIG, c[t][tt] = BIG;
    };

    set<ii> edges;
    void add(int u, int v, int w) {
        if (edges.count({u, v})) return;
        edges.insert({u, v});
        c[u][v] += w;
        g[u].push_back(v), g[v].push_back(u);
    }

    int saturate() {
        // Adds flow to the flow network until it is saturated.
        // Uses the "Capacity Scaling" method: https://youtu.be/1ewLrXUz4kk
        // Returns the Max-Flow Min-Cut of the network when saturated.

        vb m(n, false);
        for (int r, f = BIG; f > 0; f /= 2, fill(all(m), false)) {
            while (r = improve(ss, s, f, BIG, m)) {
                fill(all(m), false);
                curf += r;
            }
        }

        return curf;
    }

   protected:
    int ss, tt;
    int improve(int u, int v, int minf, int maxf, vb& m) {
        // Preforms a single iteration of the capacity scaling algorithm.
        // Tries to add f units of flow to the network, starting from edge
        // (u,v), where minf<=f<=maxf. Returns the number of flow units added to
        // the total flow network. If can't add more flow to the networt, the
        // network is saturated, and 0 is returned.

        if (v == tt) return maxf;
        if (m[v] || c[u][v] < minf) return false;
        m[v] = true, maxf = min(maxf, c[u][v]);

        for (int k : g[v]) {
            int r = improve(v, k, minf, maxf, m);
            if (r) {
                c[u][v] -= r, c[v][u] += r;
                return r;
            }
        }

        return false;
    }
};

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;

    int s = 0, t = n + m + 1;
    flow nf(n + m + 2, s, t);

    for (int i = 1; i <= n; i++) nf.add(s, i, 1);
    for (int i = n + 1; i <= n + m; i++) nf.add(i, t, 1);

    fori(k, i) {
        int a, b;
        cin >> a >> b;
        nf.add(a, n + b, 1);
    }

    cout << nf.saturate() << endl;
    for (int i = 1; i <= n; i++)
        for (int c : nf.g[i])
            if (c != s && nf.c[i][c] == 0) cout << i << ' ' << (c - n) << endl;
}
