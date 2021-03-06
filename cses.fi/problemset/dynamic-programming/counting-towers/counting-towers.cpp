// a10n - Mon Mar 28 11:05:49 2022
// Counting Towers (https://cses.fi/problemset/task/2413)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;
#define int long long

// a: |_|_|

// b: |   |

// c: |_| |
//    | | |

// d: | | |
//    | | |

const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
int dp[maxn];

void computedp() {
    int a = 1, b = 1, c = 0, d = 0;
    dp[1] = 2;
    for (int i = 2; i < maxn; i++) {
        int an = a + b + c + d;
        int bn = a + b + b + c + d;
        int cn = a + a + d + d + c + c;
        int dn = a + c + d;
        a = an % MOD, b = bn % MOD, c = cn % MOD, d = dn % MOD;
        dp[i] = (a + b + c + d) % MOD;
    }
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    computedp();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}
