#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

#ifndef _debug
int main() {
    ld l, x, y, s, d, cw, ccw;
    cin >> l >> x >> y >> s >> d;
    if(d == s) {
        cout << 0 << endl;
        return 0;
    }

    if(d >= s) {
        cw = abs(d - s);
        ccw = s + (l - d);
    } else {
        cw = l - s + d;
        ccw = s - d;
    }
    if(x >= y) {
        cout << fixed << setprecision(12) << cw / (x + y) << endl;
        return 0;
    }
    ld ans = min(cw / (x + y), ccw / (y - x));
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}
#endif