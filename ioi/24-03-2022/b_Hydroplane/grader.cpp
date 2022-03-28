#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Hydroplane.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M, H, S, T;
    cin >> N >> M >> H >> S >> T;

    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<int> X(H), Y(H);
    for (int i = 0; i < H; i++) {
        cin >> X[i] >> Y[i];
    }

    cout << MinimalCost(N, M, H, S, T, A, B, C, X, Y) << "\n";
    return 0;
}
