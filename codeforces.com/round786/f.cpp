#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
const int maxn = 1005;
bool b[maxn][maxn];
int n, m, sz, inside;

int toi(int i, int j) { return (j * n) + i + 1; }
bool ith(int i) {
    i--;
    return b[i % n][i / n];
}

int solve() {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int i = toi(x, y);
    b[x][y] = !b[x][y];
    if (!b[x][y]) {
        if (i <= sz) inside--;
        if (ith(sz--)) inside--;
    } else {
        if (i <= sz) inside++;
        if (ith(++sz)) inside++;
    }
    return sz - inside;
}

signed main() {
    int t;
    cin >> n >> m >> t;
    fori(n, i) fori(m, j) {
        char c;
        cin >> c;
        b[i][j] = c == '*';
        sz += c == '*';
    }
    for (int i = 1; i <= sz; i++)
        if (ith(i)) inside++;
    while (t--) cout << solve() << endl;
}
