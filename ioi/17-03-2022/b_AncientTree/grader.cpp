#include <bits/stdc++.h>

#include "AncientTree.h"
using namespace std;

void UList(std::vector<int> &U) {
    for (int num : U) cout << num << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];
    RestoreAncientTree(N, V);
    return 0;
}
