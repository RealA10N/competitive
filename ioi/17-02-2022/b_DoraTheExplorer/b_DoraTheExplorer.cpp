#include <bits/stdc++.h>
using namespace std;

const int maxx = 2e6 + 5;
const int sqrtmaxx = 1450;

bool p[maxx];
int a[maxx];

void Prepare() {
    for (int i = 0; i < maxx; i++) p[i] = true;
    for (int i = 0; i < maxx; i++) a[i] = 1;

    for (int i = 2; i < sqrtmaxx; i++)
        for (int j = i; i * j < maxx; j++) p[i * j] = false;

    for (int i = 2; i < sqrtmaxx; i++) {
        for (int j = i; i * j < maxx; j++) {
            if (!p[i]) a[i * j]++;
            if (!p[j] && i != j) a[i * j]++;
        }
    }
}

int HowMany(int X) { return a[X] + !p[X]; }
