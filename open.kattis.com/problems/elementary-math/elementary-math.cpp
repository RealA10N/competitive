// a10n - Sun Feb  6 23:10:28 2022
// Elementary Math (https://open.kattis.com/problems/elementarymath)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<ii> vii;

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

    void add(int u, int v, int w) {
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

const int maxn = 10002;
const int s = 10'000, t = 10'001;
flow nf(maxn, s, t);

map<ii, char> edgeOps;
map<int, int> resToId, idToRes;

int j = 2'500;

void add(int i, int res, char op) {
    if (!resToId.count(res)) {
        resToId[res] = j, idToRes[j++] = res;
        nf.add(resToId[res], t, 1);
    }
    if (!edgeOps.count({i, resToId[res]})) {
        nf.add(i, resToId[res], 1);
        edgeOps[{i, resToId[res]}] = op;
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin >> n;

    vii orig(n);
    fori(n, i) {
        int a, b;
        cin >> a >> b;
        orig[i] = {a, b};
        nf.add(s, i, 1);
        add(i, a + b, '+');
        add(i, a - b, '-');
        add(i, a * b, '*');
    }

    if (nf.saturate() != n) {
        cout << "impossible" << endl;
    } else {
        fori(n, i) {
            for (int k : nf.g[i])
                if (k != s && nf.c[i][k] == 0)
                    cout << orig[i].first << ' ' << edgeOps[{i, k}] << ' '
                         << orig[i].second << " = " << idToRes[k] << endl;
        }
    }
}
