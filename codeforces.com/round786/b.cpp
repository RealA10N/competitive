#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ltrs = 'z' - 'a' + 1;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        char a, b;
        cin >> a >> b;
        int ai = a - 'a', bi = b - 'a';
        cout << (ai * (ltrs - 1)) + bi + (bi < ai) << endl;
    }
}
