#include <bits/stdc++.h>

#include "Party.h"
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
#define fori(n, i) for (int i = 0; i < n; i++)

const int maxn = 2e5 + 5;
vi g[maxn];

bool QInParty(int N, int F, int Q, int X, vi A, vi B) {
    fori(F, i) g[A[i]].push_back(B[i]), g[B[i]].push_back(A[i]);

    vi friends(N + 1);  // -1 if left
    fori(N + 1, i) friends[i] = g[i].size();

    queue<int> q;
    q.push(X), friends[X] = -1;

    while (q.size()) {
        int a = q.front();
        q.pop();

        for (int b : g[a]) {
            if (friends[b] == -1) continue;
            if (--friends[b] <= (g[b].size() / 2)) friends[b] = -1, q.push(b);
        }
    }

    return friends[Q] != -1;
}
