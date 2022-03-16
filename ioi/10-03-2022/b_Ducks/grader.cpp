#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "Ducks.h"
using namespace std;

void ans(int n) { cout << n << endl; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int L;
    int R;
    int Y;

    cin >> N >> L >> R >> Y;
    vector<int> x(N);
    vector<int> v(N);
    vector<int> h(N);

    for (long long i = 0; i < N; ++i) cin >> x[i] >> v[i] >> h[i];

    Hide(N, L, R, Y, x, v, h);
    return 0;
}
