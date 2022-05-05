#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef vector<bool> vb;

const int maxn = 1e5 + 5;
vi gt[maxn];

signed main() {
    int n;
    cin >> n;
    vi as(n), vs(n), deg(n, 0);
    fori(n, i) {
        cin >> as[i] >> vs[i];
        as[i]--;
        gt[as[i]].push_back(i);
        deg[as[i]]++;
    }

    vb vis(n, false);
    queue<int> q;
    int ans = 0;
    fori(n, i) if (!deg[i]) q.push(i);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true, ans += vs[u];
        int v = as[u];
        if (--deg[v] == 0) q.push(v);
    }

    fori(n, i) {
        if (!vis[i]) {
            vis[i] = true;
            int u = as[i], mi = vs[i];
            ans += vs[i];
            while (!vis[u]) {
                vis[u] = true;
                ans += vs[u];
                mi = min(mi, vs[u]);
                u = as[u];
            }
            ans -= mi;
        }
    }

    cout << ans << endl;
}
