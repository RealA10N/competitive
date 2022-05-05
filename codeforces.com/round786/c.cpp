#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve() {
    string s, t;
    cin >> s >> t;
    if (t.size() > 1) {
        for (char a : t)
            if (a == 'a') return -1;
        return 1LL << s.size();
    } else {
        if (t[0] == 'a') return 1;
        return 1LL << s.size();
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
}
