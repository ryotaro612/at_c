#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

static const ld PI = 3.141592653589793;

pair<ld, ld> solve(int n, ld x, ld y, ld x2, ld y2) {
    ld xm = (x + x2) / (ld)2, ym = (y + y2) / (ld)2;
    ld vec_x = x - xm, vec_y = y - ym;

    ld dec = (ld)360 / (ld)n;
    ld rad = PI * dec / (ld)180;

    ld vec_xc = (ld)cos(rad) * vec_x - (ld)sin(rad) * vec_y,
       vec_yc = (ld)sin(rad) * vec_x + (ld)cos(rad) * vec_y;

    return make_pair(xm + vec_xc, ym + vec_yc);
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    ld x, y, x2, y2;
    cin >> n >> x >> y >> x2 >> y2;
    pair<ld, ld> res = solve(n, x, y, x2, y2);
    cout << fixed << setprecision(12) << res.first;
    cout << " ";
    cout << fixed << setprecision(12) << res.second << endl;
}
#endif