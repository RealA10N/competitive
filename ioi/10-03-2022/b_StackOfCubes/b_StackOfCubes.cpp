#include <bits/stdc++.h>

#include "StackOfCubes.h"
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
#define fori(n, i) for (int i = 0; i < n; i++)

const int maxn = 1e5 + 5;
queue<int> qs[maxn];

vi ans;
void calcans(int i) {
    ans.push_back(i);
    while (qs[i].size()) {
        calcans(qs[i].front());
        qs[i].pop();
    }
}

string FinalStack(int N, vs stacks, vi A, vi B) {
    if (N == 1) return stacks[0];

    fori(N - 1, i) A[i]--, B[i]--;
    fori(N - 1, i) qs[A[i]].push(B[i]);
    calcans(A.back());

    string ret;
    for (int i : ans) ret.append(stacks[i]);
    return ret;
}
