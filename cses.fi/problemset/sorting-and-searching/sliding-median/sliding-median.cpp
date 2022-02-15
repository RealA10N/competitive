// a10n - Wed Feb 16 00:23:02 2022
// Sliding Median (https://cses.fi/problemset/task/1076)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    fori(n, i) cin >> x[i];

    multiset<int> hi, lo;
    fori(k, i) lo.insert(x[i]);
    fori(k / 2, i) hi.insert(*lo.rbegin()), lo.erase(lo.find(*lo.rbegin()));

    int me = *lo.rbegin();
    cout << me << ' ';

    for (int i = k; i < n; i++) {
        bool rehi = x[i - k] > me, adhi = x[i] >= me;

        if (adhi) hi.insert(x[i]);
        else lo.insert(x[i]);

        if (rehi) hi.erase(hi.find(x[i-k]));
        else lo.erase(lo.find(x[i-k]));

        if (adhi && !rehi) lo.insert(*hi.begin()), hi.erase(hi.begin());
        if (!adhi && rehi) hi.insert(*lo.rbegin()), lo.erase(lo.find(*lo.rbegin()));

        cout << (me = *lo.rbegin()) << ' ';
    }

    cout << endl;
}
