#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef vector<bool> vb;

signed main() {
    string s;
    cin >> s;

    int n = s.size();
    vi cs(n + 1, 0), os(n + 1, 0), ws(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cs[i] = cs[i - 1];
        os[i] = os[i - 1];
        ws[i] = ws[i - 1];
        if (s[i - 1] == 'C') cs[i]++;
        if (s[i - 1] == 'O') os[i]++;
        if (s[i - 1] == 'W') ws[i]++;
    }

    int q;
    cin >> q;
    while (q--) {
        int lo, hi;
        cin >> lo >> hi;
        int c = cs[hi] - cs[lo - 1];
        int o = os[hi] - os[lo - 1];
        int w = ws[hi] - ws[lo - 1];
        c %= 2, o %= 2, w %= 2;
        if (c && !o && !w)
            cout << "Y";
        else if (!c && o && w)
            cout << "Y";
        else
            cout << "N";
    }

    cout << endl;
}
