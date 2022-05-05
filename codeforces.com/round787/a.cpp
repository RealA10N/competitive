#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        x -= a, y -= b;
        x = max(x, 0LL);
        y = max(y, 0LL);
        cout << (x + y <= c ? "YES" : "NO") << endl;
    }
}
