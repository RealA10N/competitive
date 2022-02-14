// a10n - Mon Feb 14 09:09:29 2022
// Towers (https://cses.fi/problemset/task/1073)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin >> n;
    multiset<int> s;
    fori(n, i) {
        int a;
        cin >> a;
        set<int>::iterator it = s.upper_bound(a);
        if (it != s.end()) s.erase(it);
        s.insert(a);
    }

    cout << s.size() << endl;
}