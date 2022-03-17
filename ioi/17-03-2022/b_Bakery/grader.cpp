#include <bits/stdc++.h>
using namespace std;
#include "bakery.h"

typedef long long ll;

void Inv(ll num) { cout << num << endl; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    ProblemLaPastry(N, A);
    return 0;
}
