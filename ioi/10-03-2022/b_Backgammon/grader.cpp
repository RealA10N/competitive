#include <bits/stdc++.h>
#include "backgammon.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;




int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;

    vector<int> V(N, 0);
    vector<int> M(N, 0);
    vector<int> D(N, 0);
    vector<int> G;
    for (int i = 0; i < N; ++i) {
        //int v, m, d;
        cin >> V[i] >> M[i] >> D[i];

        for (int j = 0; j <D[i] ; ++j) {
            int u;
            cin >> u;
            G.push_back(u);

        }
    }
    int ans= Backgammon (N,V,M,D,G);
    cout << ans << endl;





    return 0;
}
