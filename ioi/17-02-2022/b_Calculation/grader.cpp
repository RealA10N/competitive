#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "Calculation.h"

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::string F;
    std::cin >> F;
    int ans = calculate(F);
    printf("%d\n", ans);
    return 0;
}
