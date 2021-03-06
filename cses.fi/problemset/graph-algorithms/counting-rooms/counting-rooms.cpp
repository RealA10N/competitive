// a10n - Mon Jan 31 09:39:57 2022
// Counting Rooms (https://cses.fi/problemset/task/1192)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
typedef pair<int, int> ii;

const int maxn = 1005;
char b[maxn][maxn];
bool e[maxn][maxn];
const pair<int, int> deltas[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;
bool bfs(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m) return false;
    if (b[i][j] == '#' || e[i][j]) return false;
    e[i][j] = true;
    for (ii d : deltas) bfs(d.first + i, d.second + j);
    return true;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;
    fori(n, i) fori(m, j) cin >> b[i][j];
    fori(n, i) fori(m, j) e[i][j] = false;
    int res = 0;
    fori(n, i) fori(m, j) res += bfs(i, j);
    cout << res << endl;
}
