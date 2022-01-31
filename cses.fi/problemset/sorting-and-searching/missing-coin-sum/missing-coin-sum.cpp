// a10n - Mon Jan 31 22:57:10 2022
// Missing Coin Sum (https://cses.fi/problemset/task/2183)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)

typedef vector<int> vi;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin >> n;
    vi x(n);
    fori(n, i) cin >> x[i];
    sort(all(x));
    int d = 0;
    for (int v : x) {
        if (v - d > 1) break;
        d += v;
    }
    cout << d + 1 << endl;
}
