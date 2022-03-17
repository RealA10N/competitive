#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Magician.h"
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int T, C, R;
    std::cin >> T;
    while (T--) {
        std::cin >> C >> R;
        PrepareTheMagic(C, R);

        int X;
        for (int i = 0; i < R; i++) {
            std::cin >> X;
            cout << DoTheMagic(X) << " ";
        }
        cout << "\n";
    }
    return 0;
}
