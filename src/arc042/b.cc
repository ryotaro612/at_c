#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

ld calc_dist(ld x1, ld y1, ld x2, ld y2, ld x, ld y) {
    if(y1 == y2)
        return abs(y - y1);
    if(x1 == x2)
        return abs(x1 - x);
    ld alpha = (x1 - x2) / (y2 - y1);
    ld beta = y - alpha * x;

    ld alpha1 = (y2 - y1) / (x2 - x1);
    ld beta1 = y1 - alpha1 * x1;
    ld cross_x = (beta1 - beta) / (alpha - alpha1);
    ld cross_y = (alpha * beta1 - beta * alpha1) / (alpha - alpha1);
    return dist(x, y, cross_x, cross_y);
}

ld solve(ld x, ld y, int n, vector<ld> xv, vector<ld> yv) {
    ld res = 10000000;
    for(int i = 0; i < n; i++)
        res =
            min(calc_dist(xv[i], yv[i], xv[(i + 1) % n], yv[(i + 1) % n], x, y),
                res);
    return res;
}

#ifndef _debug
int main() {
    ld x, y;
    int n;
    cin >> x >> y >> n;
    vector<ld> xv(n), yv(n);
    for(int i = 0; i < n; i++)
        cin >> xv[i] >> yv[i];
    cout << fixed << setprecision(12) << solve(x, y, n, xv, yv) << endl;
    return 0;
}
#endif