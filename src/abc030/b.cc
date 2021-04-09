#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

#ifndef _LOCAL
int main() {
    ld n, m;
    cin >> n >> m;
    n = (int)n % 12;
    n = (ld)n;
    ld deg_l = (ld)360 * m / (ld)60;
    ld deg_s = (ld)360 * ((ld)n / (ld)12) + (ld)30 * m / (ld)60;
    ld res = max(deg_l, deg_s) - min(deg_l, deg_s);
    //cout << deg_l << " " << deg_s << endl;
    cout << fixed << setprecision(12) << min(res, (ld)360 - res) << endl;
}
#endif