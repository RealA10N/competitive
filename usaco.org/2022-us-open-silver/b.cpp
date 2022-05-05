#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(n, i) for (int i = 0; i < n; i++)
typedef vector<int> vi;

const int LTRS = 'r' - 'a' + 1;
bool good[LTRS][LTRS];
string a, b;

bool is_good(char l1, char l2) {
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        while (i < a.size() && a[i] != l1 && a[i] != l2) i++;
        while (j < b.size() && b[j] != l1 && b[j] != l2) j++;
        if (i < a.size() && j < b.size()) {
            if (a[i] != b[j]) return false;
            i++, j++;
        }
    }

    while (i < a.size() && a[i] != l1 && a[i] != l2) i++;
    while (j < b.size() && b[j] != l1 && b[j] != l2) j++;
    return i == a.size() && j == b.size();
}

signed main() {
    cin >> a >> b;
    fori(LTRS, i) fori(LTRS, j) good[i][j] = good[j][i] =
        is_good('a' + i, 'a' + j);

    int q;
    cin >> q;
    while (q--) {
        string c;
        cin >> c;
        bool cool = true;
        for (char l1 : c)
            for (char l2 : c) cool = cool && good[l1 - 'a'][l2 - 'a'];
        cout << (cool ? "Y" : "N");
    }

    cout << endl;
}
