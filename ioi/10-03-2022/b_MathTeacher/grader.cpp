#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "MathTeacher.h"

int readInt() {
    int i;
    if (scanf("%d", &i) != 1) {
        fprintf(stderr, "Error while reading input\n");
        exit(1);
    }
    return i;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    int N, K;
    N = readInt();
    K = readInt();
    std::vector<int> A(N), P(K);
    for (int i = 0; i < N; i++) {
        A[i] = readInt();
    }
    for (int i = 0; i < K; i++) {
        P[i] = readInt();
    }
    std::vector<int> ans = AmountOfWays(N, K, A, P);
    for (int i = 0; i < K; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
