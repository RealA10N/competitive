#include <bits/stdc++.h>

#include "Ammunition.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    init(N, Q);
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int A, B, C;
            cin >> A >> B >> C;
            aid(A, B, C);
        } else {
            int D;
            cin >> D;
            int ans;
            ans = check(D);
            cout << ans << "\n";
        }
    }
    return 0;
}
