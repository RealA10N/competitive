// a10n - Mon Mar 28 12:30:49 2022
// Guess the Number (https://open.kattis.com/problems/guess)
// Generated by cptk

#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int hi = 1000, lo = 1;
    string s;
    while (s != "correct") {
        int mi = (hi + lo) / 2;
        cout << mi << endl;
        cin >> s;
        if (s == "lower") hi = mi - 1;
        if (s == "higher") lo = mi + 1;
    }
}
