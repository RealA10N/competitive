#include <bits/stdc++.h>
using namespace std;

#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vector<char>> vvc;

const int MOVES = 4;
int dx[MOVES] = {1, 0, 0, -1};
int dy[MOVES] = {0, 1, -1, 0};

bool isMineNear(int x, int y, const vvc& world) {
    fori(MOVES, i) if (world[x + dx[i]][y + dy[i]] == 'M') return true;
    return false;
}

int dfs(int i, int j, const vvc& world, vvb& vis) {
    if (world[i][j] == '#' || vis[i][j]) return 0;
    vis[i][j] = true;
    int count = world[i][j] == 'G';
    if (isMineNear(i, j, world)) return count;
    fori(MOVES, k) count += dfs(i + dx[k], j + dy[k], world, vis);
    return count;
}

int Grapes(int N, int M, vvc world) {
    int lx, ly;
    fori(N, x) fori(M, y) if (world[x][y] == 'L') lx = x, ly = y;
    vvb vis(N, vb(M, false));
    return dfs(lx, ly, world, vis);
}
