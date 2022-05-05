#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve() {
    string s;
    cin >> s;
    if (s.length() == 1) return 1;
    bool sus = true;
    int len = 0;
    for (char c : s) {
        if (c == '0' && sus) return len + 1;
        if (c == '1') sus = true, len = 1;
        if (c == '?' && sus) len++;
    }
    return len;
}

signed main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
}
