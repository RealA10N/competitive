#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, char> m;
    for (int i = 'a'; i <= 'z'; i++) m[i] = i;
    for (char c : s) {
        if (m[c] == 'a') continue;
        while (k && m[c] > 'a') {
            k--;
            char cc = m[c];
            for (char i = 'a'; i <= 'z'; i++)
                if (m[i] == cc) m[i] = m[m[i] - 1];
        }
    }

    for (char c : s) cout << m[c];
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}
