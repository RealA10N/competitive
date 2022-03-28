//#define _CRT_SECURE_NO_WARNINGS
#include "MoleFamily.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

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
    int N, M;
    N = readInt();
    M = readInt();
    std::vector<int> X(M), Y(M);
    for (int i = 0; i < M; i++) {
        X[i] = readInt();
        Y[i] = readInt();
    }
    int K;
    K = readInt();
    std::vector<int> A(K), B(K);
    for (int i = 0; i < K; i++)
    {
        A[i] = readInt();
        B[i] = readInt();
    }
    int ans = BestPit(N, M,K, X, Y, A, B);
    printf("%d\n", ans);
    return 0;
}
