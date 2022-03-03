#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "Cookies.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<int> A(N - 1);
    vector<int> B(N - 1);
    for (int i = 0; i < N - 1; i++) cin >> A[i] >> B[i];
    long long ans = Cookies(N, A, B);
    cout << ans << endl;
    return 0;
}
