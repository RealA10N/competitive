#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
#define fori(n, i) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
const int oo = 1e10;

// signed main() {
//     int n;
//     cin >> n;
//     vi a(n);
//     fori(n, i) cin >> a[i];

//     int mi = oo;
//     vi mins(3, oo);
//     for (int i = 0; i < n; i++) {
//         int my = (a[i] + 1) / 2;

//         mins[2] = my;
//         sort(all(mins));

//         int near = oo;
//         if (i > 0) {
//             int left = max<int>(a[i - 1] - my, 0);
//             near = min(near, left);
//         }
//         if (i + 1 < n) {
//             int left = max<int>(a[i + 1] - my, 0);
//             near = min(near, left);
//         }

//         mi = min(mi, my + near);
//     }

//     cout << min(mi, mins[0] + mins[1]) << endl;
// }

signed main() {
    int n;
    cin >> n;
    vi a(n);
    fori(n, i) cin >> a[i];

    vi mins(3, oo);
    for (int i = 0; i < n; i++) mins[2] = (a[i] + 1) / 2, sort(all(mins));
    int mi = mins[0] + mins[1];

    for (int i = 0; i + 1 < n; i++) {
        int x = a[i], y = a[i + 1];
        int mx = x / 3, my = y / 3;
        int pops = 0;
        x -= 3 * min(mx, my), y -= 3 * min(mx, my);
        pops += 2 * min(mx, my);
        pops += (x + y + 2) / 3;
        mi = min(mi, pops);
    }

    for (int i = 1; i + 1 < n; i++) {
        int x = a[i - 1], y = a[i + 1];
        int mix = min(x, y), ma = max(x, y);
        int left = ((ma - mix) + 1) / 2;
        mi = min(mi, mix + left);
    }

    cout << mi << endl;
}
