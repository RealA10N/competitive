// a10n - Mon Feb 14 14:17:19 2022
// Maximum Subarray Sum (https://cses.fi/problemset/task/1643)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)

const int MIN = -1e10;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n, including = MIN, excluding = MIN;
    cin >> n;
    fori(n, i) {
        int a;
        cin >> a;
        including = max(a, a + including);
        excluding = max(including, excluding);
    }

    cout << max(including, excluding) << endl;
}