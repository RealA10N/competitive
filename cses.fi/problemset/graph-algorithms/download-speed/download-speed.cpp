// a10n - Fri Feb  4 20:07:37 2022
// Download Speed (https://cses.fi/problemset/task/1694)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define fori(n, i) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

struct mf {
    vvi g, c;
    int n, s, t, curf = 0;
    const int BIG = 1LL << 60;

    mf(int n, int s, int t)
        : g(n + 2, vi()), c(n + 2, vi(n + 2, 0)), n(n), s(s), t(t) {
        // we use node n as dummy s and n+1 as dummy t.
        g[n].push_back(s), g[t].push_back(n + 1);
        c[n][s] = BIG, c[t][n + 1] = BIG;
    };

    void add(int u, int v, int w) {
        c[u][v] += w;
        g[u].push_back(v), g[v].push_back(u);
    }

    void improve() {
        vb m(n, false);
        for (int r, f = BIG; f > 0; f /= 2, fill(all(m), false)) {
            while (r = improve(n, s, f, BIG, m)) {
                fill(all(m), false);
                curf += r;
            }
        }
    }

   protected:
    int improve(int u, int v, int minf, int maxf, vb& m) {
        // returns amount of flow improved.
        // if there is no mesila magdila, returns false (zero).

        if (v == n + 1) return maxf;
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
    int n, m;
    cin >> n >> m;
    mf mf(n + 1, 1, n);

    fori(m, i) {
        int a, b, c;
        cin >> a >> b >> c;
        mf.add(a, b, c);
    }

    mf.improve();
    cout << mf.curf << endl;
}