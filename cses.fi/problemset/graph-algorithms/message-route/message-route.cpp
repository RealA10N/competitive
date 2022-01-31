// a10n - Mon Jan 31 20:07:39 2022
// Message Route (https://cses.fi/problemset/task/1667)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
#define pb push_back

typedef vector<int> vi;
const int maxn = 2e5;
vi g[maxn];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fori(m, i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b), g[b].pb(a);
    }

    vi path(n, -1);
    queue<int> q;
    q.push(0);
    path[0] = -2;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int s : g[i]) {
            if (path[s] == -1) {
                q.push(s);
                path[s] = i;
            }
        }
    }

    if (path[n - 1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        stack<int> s;
        int i = n - 1;
        while (i != -2) s.push(i), i = path[i];
        cout << s.size() << endl;
        while (!s.empty()) {
            cout << ++s.top() << ' ';
            s.pop();
        }
        cout << endl;
    }
}
