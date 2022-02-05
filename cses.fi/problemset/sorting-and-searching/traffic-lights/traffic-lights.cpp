// a10n - Thu Feb  3 14:07:04 2022
// Traffic Lights (https://cses.fi/problemset/task/1163)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)

typedef pair<int, int> ii;

inline bool invalid(ii interval, const set<int>& s) {
    int len = interval.first, start = interval.second;
    int end = *s.upper_bound(start);
    return end != start + len;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int x, n;
    cin >> x >> n;

    set<int> s;
    priority_queue<ii> q;  // {length, start}
    s.insert(0), s.insert(x);

    fori(n, i) {
        int a;
        cin >> a;

        auto it = s.upper_bound(a);
        int hi = *it, lo = *(--it);

        s.insert(a), q.push({a - lo, lo}), q.push({hi - a, a});
        while (!q.empty() && invalid(q.top(), s)) q.pop();

        cout << q.top().first << ' ';
    }

    cout << endl;
}