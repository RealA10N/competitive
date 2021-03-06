// a10n - Wed Feb  2 01:03:45 2022
// Round Trip (https://cses.fi/problemset/task/1669)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;

const int maxn = 1e5 + 5;
vi g[maxn];
int d[maxn];
int D = 0;

int explore(int i) {
    // returns -1 if no loop, or the depth of loop if found one.

    if (d[i] != -1)
        if (D - d[i] > 2) {
            cout << D - d[i] + 1 << endl << i + 1 << ' ';
            return D - d[i];
        } else {
            return -1;
        }

    d[i] = D++;

    for (int s : g[i]) {
        int r = explore(s);
        if (r > 0) {
            cout << i + 1 << ' ';
            return r - 1;
        } else if (r == 0)
            return 0;
    }

    D--;
    return -1;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fori(n, i) d[i] = -1;
    fori(m, i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b), g[b].push_back(a);
    }

    bool res = false;
    fori(n, i) if (explore(i) == 0) {
        res = true;
        break;
    }

    if (!res) cout << "IMPOSSIBLE";
    cout << endl;
}
