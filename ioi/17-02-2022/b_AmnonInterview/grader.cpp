#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "AmnonInterview.h"

int X[105], Y[105];
int R, C, K, N, count = 0;

int query(int x, int y) {
    count++;
    if (count > K || x < 1 || y < 1 || x > R || y > C) {
        printf("-1\n");
        exit(0);
    }
    int res = 0;
    for (int i = 0; i < N; i++) res += abs(X[i] - x) + abs(Y[i] - y);
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> R >> C >> K >> N;
    for (int i = 0; i < N; i++) std::cin >> X[i] >> Y[i];
    int ans = Interview(R, C, K);
    printf("%d\n", ans);
    return 0;
}
