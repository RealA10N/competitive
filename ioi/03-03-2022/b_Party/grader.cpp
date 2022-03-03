#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Party.h"
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int N, F, Q, X;
    std::cin >> N >> F >> Q >> X;

    std::vector<int> A(F);
    std::vector<int> B(F);

    for (int i = 0; i < F; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::cout << (QInParty(N, F, Q, X, A, B) ? "stay" : "leave") << std::endl;

    return 0;
}
