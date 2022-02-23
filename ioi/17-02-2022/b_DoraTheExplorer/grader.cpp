#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "DoraTheExplorer.h"

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Q;
    std::cin >> Q;
    Prepare();
    int X;
    for (int i = 0; i < Q; i++) {
        std::cin >> X;
        printf("%d\n", HowMany(X));
    }
    return 0;
}
