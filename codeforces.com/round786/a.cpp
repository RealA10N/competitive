#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int x, y;
    cin >> x >> y;
    if (y % x) {
        cout << "0 0" << endl;
    } else {
        cout << 1 << " " << y / x << endl;
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}
