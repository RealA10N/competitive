#include <bits/stdc++.h>

#include "AncientTree.h"
using namespace std;

typedef vector<int> vi;

void RestoreAncientTree(int N, vi V) {
    N++;
    vi deg(N + 1, 0);
    for (int v : V) deg[v]++;
    set<int> leaves;
    for (int u = 1; u <= N; u++)
        if (!deg[u]) leaves.insert(u);

    bool valid = V[0] != 1 && V[V.size() - 1] == N;
    vi ans;

    for (int v : V) {
        if (leaves.empty()) {
            valid = false;
            break;
        }

        auto begin = leaves.begin();
        ans.push_back(*begin), leaves.erase(begin);
        if (!--deg[v]) leaves.insert(v);
    }

    if (!valid) ans.assign(V.size(), -1);
    UList(ans);
}
