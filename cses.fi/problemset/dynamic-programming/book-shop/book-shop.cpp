// a10n - Sat Mar 26 23:20:29 2022
// Book Shop (https://cses.fi/problemset/task/1158)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vi h(n), s(n);
    fori(n, i) cin >> h[i];
    fori(n, i) cin >> s[i];

    vi cur(x + 1, 0), prev(x + 1, 0);

    fori(n, ni) {
        fori(x + 1, xi) if (xi - h[ni] >= 0) cur[xi] =
            max(cur[xi], prev[xi - h[ni]] + s[ni]);
        prev = cur;
    }

    cout << *max_element(all(cur)) << endl;
}
