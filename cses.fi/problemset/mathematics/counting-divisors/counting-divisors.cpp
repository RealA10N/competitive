// a10n - Sat Feb 19 12:49:20 2022
// Counting Divisors (https://cses.fi/problemset/task/1713)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)

typedef vector<int> vi;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vi a(n);
    fori(n, i) cin >> a[i];
    int ma = *max_element(all(a));
    vi b(ma + 1);
    for (int i = 1; i <= ma; i++)
        for (int j = 1; j * i <= ma; j++) b[i * j]++;
    fori(n, i) cout << b[a[i]] << endl;
}
