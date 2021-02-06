#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll solve(ld x, ld y, ld r) {
    ll res = 0ll;
    ll top = floor(y + r);
    ll under = ceil(y - r);
    r= nextafter(r, INFINITY);

    for(ll i = top; i >= under; i--) {
        ld width = sqrt(r * r - abs(i - y) * abs(i - y));
        res += floor(x + width) - ceil(x - width) + 1;
    }

    return res;
}
/*
int main() {
    ld x, y, r;
    cin >> x >> y >> r;
    cout << solve(x, y, r) << endl;
}
*/