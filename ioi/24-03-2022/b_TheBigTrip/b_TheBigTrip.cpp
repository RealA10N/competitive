#include <bits/stdc++.h>
using namespace std;
#define fori(n, i) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

const int maxn = 1e5 + 5;
vi g[maxn];

ll moves(deque<ll> q, bool front, int w) {
    ll p = w;
    ll m = 0;
    while (q.size()) {
        if (front) {
            m += max(abs(p - q.front()), abs(w - q.front()));
            p = q.front(), q.pop_front();
        } else {
            m += max(abs(p - q.back()), abs(w - q.back()));
            p = q.back(), q.pop_back();
        }
        front = !front;
    }

    return m;
}

vl GetWaitTimes(int n, int w, vi h) {
    sort(all(h));
    int top = max(w, h[n - 1]), btm = min(w, h[0]);
    vl ans = {top - btm};

    deque<ll> dq;
    for (int i : h) dq.push_back(i);
    ans.push_back(max(moves(dq, true, w), moves(dq, false, w)));
    return ans;
}
