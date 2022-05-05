#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve() {
    int n;
    cin >> n;
    vi a(n);
    fori(n, i) cin >> a[i];
    int c = 0;
    for (int i = n - 1; i > 0; i--) {
        while (a[i - 1] >= a[i]) {
            if (a[i - 1] == 0) return -1;
            a[i - 1] /= 2, c++;
        }
    }
    return c;
}

signed main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
}
