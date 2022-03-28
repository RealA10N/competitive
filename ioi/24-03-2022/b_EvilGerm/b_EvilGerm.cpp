#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define fori(n, i) for (int i = 0; i < n; i++)

const int maxn = 1200;
const int maxr = 45;
vii g[maxr][maxr];
bool dead[maxr][maxr];

int R;
inline ii inxToXy(int i) {
    int l = R;
    for (int h = 1; h <= R; h++, i -= l++) {
        if (i <= l) return {h, i};
    }

    l -= 2;
    for (int h = 1; h <= R - 1; h++, i -= l--) {
        if (i <= l) return {R + h, i};
    }

    throw exception();
}

inline void add(ii a, ii b) {
    if (dead[a.first][a.second] || dead[b.first][b.second]) return;
    g[a.first][a.second].push_back(b);
    g[b.first][b.second].push_back(a);
}

int dist(ii s, ii t) {
    queue<ii> q;
    q.push(s);
    vvi d(maxr, vi(maxr, -1));
    d[s.first][s.second] = 0;
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x == t.first && y == t.second) return d[x][y];
        for (ii p : g[x][y]) {
            int xn = p.first, yn = p.second;
            if (d[xn][yn] != -1) continue;
            d[xn][yn] = d[x][y] + 1;
            q.push(p);
        }
    }

    return d[t.first][t.second];
}

int EvilGerm(int r, int n, int a, int b, int x, vi s) {
    R = r;
    fori(maxr, i) fori(maxr, j) dead[i][j] = false;
    fori(x, i) {
        ii c = inxToXy(s[i]);
        dead[c.first][c.second] = true;
    }

    int l = r;
    for (int i = 1; i <= r; i++, l++) {
        for (int j = 1; j <= l; j++) {
            if (j < l) add({i, j}, {i, j + 1});
            if (i < r) {
                add({i, j}, {i + 1, j});
                add({i, j}, {i + 1, j + 1});
            }
            if (i == r) {
                if (j < l) add({i, j}, {i + 1, j});
                if (j > 1) add({i, j}, {i + 1, j - 1});
            }
        }
    }

    l -= 2;
    for (int i = r + 1; i < 2 * r; i++, l--) {
        for (int j = 1; j <= l; j++) {
            if (j < l) add({i, j}, {i, j + 1});
            if (i + 1 < 2 * r) {
                if (j < l) add({i, j}, {i + 1, j});
                if (j > 1) add({i, j}, {i + 1, j - 1});
            }
        }
    }

    int d = dist(inxToXy(a), inxToXy(b));
    return (d <= n ? d : -1);
}
