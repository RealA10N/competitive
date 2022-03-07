#include <bits/stdc++.h>

#include "AmnonInterview.h"
using namespace std;

int Interview(int R, int C, int K) {
    int xlo = 1, xhi = R, ylo = 1, yhi = C;
    int q1, q2, q3;
    q1 = q2 = q3 = query(1, 1);

    while (xlo < xhi || ylo < yhi) {
        int xmi = (xhi + xlo + 1) / 2, ymi = (yhi + ylo + 1) / 2;
        q1 = query(xmi, ymi);

        if (xlo < xhi) {
            q2 = query(xmi - 1, ymi);
            if (q2 <= q1) xhi = xmi - 1;
            if (q2 > q1) xlo = xmi;
        }

        if (ylo < yhi) {
            q3 = query(xmi, ymi - 1);
            if (q3 <= q1) yhi = ymi - 1;
            if (q3 > q1) ylo = ymi;
        }
    }

    return min({q1, q2, q3});
}
