#include <bits/stdc++.h>
using namespace std;

#include "flow.hpp"

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    flow nf(n + 1, 1, n);

    fori(m, i) {
        int u, v, c;
        cin >> u >> v >> c;
        nf.add(u, v, c);
    }

    cout << nf.saturate() << endl;
}
