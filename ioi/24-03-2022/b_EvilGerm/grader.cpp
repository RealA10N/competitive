#include <bits/stdc++.h>

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "EvilGerm.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R, N, A, B, X;
    cin >> R >> N >> A >> B >> X;
    vector<int> S(X, 0);
    for (int i = 0; i < X; ++i) cin >> S[i];
    int ans = EvilGerm(R, N, A, B, X, S);
    cout << ans << endl;
    return 0;
}
