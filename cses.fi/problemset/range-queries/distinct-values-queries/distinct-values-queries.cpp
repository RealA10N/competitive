// a10n - Sat May 14 14:04:38 2022
// Distinct Values Queries (https://cses.fi/problemset/task/1734/)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fori(n, i) for (int i = 0; i < n; i++)
#define x first
#define y second
typedef vector<int> vi;
typedef pair<int, int> ii;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, q, sq;
    cin >> n >> q;
    sq = sqrt(n);
    vi a(n);

    map<int, int> m;
    int cur = 0;
    fori(n, i) {
        int aa;
        cin >> aa;
        if (m.count(aa))
            a[i] = m[aa];
        else
            a[i] = m[aa] = cur++;
    }

    vector<ii> qs(q);
    fori(q, i) {
        cin >> qs[i].x >> qs[i].y;
        qs[i].x--, qs[i].y--;
    }

    vi qsorder(q);
    fori(q, i) qsorder[i] = i;
    sort(all(qsorder), [&qs, &sq](int i, int j) {
        int is = qs[i].x / sq;
        int js = qs[j].x / sq;
        return (is < js) || (is == js && qs[i].y < qs[j].y);
    });

    vi ans(q);
    int lo = 0, hi = -1, sz = 0;
    vi count(n, 0);

    fori(q, i) {
        int x = qs[qsorder[i]].x, y = qs[qsorder[i]].y;

        while (x < lo)
            if (count[a[--lo]]++ == 0) sz++;
        while (hi < y)
            if (count[a[++hi]]++ == 0) sz++;
        while (lo < x)
            if (--count[a[lo++]] == 0) sz--;
        while (y < hi)
            if (--count[a[hi--]] == 0) sz--;

        ans[qsorder[i]] = sz;
    }

    fori(q, i) cout << ans[i] << endl;
}
