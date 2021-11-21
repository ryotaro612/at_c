#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(__int128_t t1, __int128_t t2, __int128_t a1, __int128_t a2,
         __int128_t b1, __int128_t b2) {
    if(t1 * a1 + t2 * a2 == b1 * t1 + b2 * t2)
        return -1ll;
    if((a1 * t1 < b1 * t1 && a1 * t1 + a2 * t2 < b1 * t1 + b2 * t2) ||
       (b1 * t1 < a1 * t1 && b1 * t1 + b2 * t2 < a1 * t1 + a2 * t2)) {
        return 0ll;
    }
    if(b1 < a1 && a2 < b2) {
        swap(a1, b1);
        swap(a2, b2);
    }
    // a1 < b1 && b2 < a2
    __int128_t ub = numeric_limits<ll>::max(), lb = -1;
    while(ub - lb > 1ll) {
        __int128_t mid = (__int128_t)(ub + lb) / (__int128_t)2;
        __int128_t dist_a = (a1 * t1 + a2 * t2) * mid,
                   dist_b = (b1 * t1 + b2 * t2) * mid;
        __int128_t dist = dist_a - dist_b;
        if(dist <= (b1 - a1) * t1) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    __int128_t dist_a = (a1 * t1 + a2 * t2) * lb,
               dist_b = (b1 * t1 + b2 * t2) * lb;
    __int128_t dist = dist_a - dist_b;
    if(dist == (b1 - a1) * t1) {
        return lb * 2ll;
    }
    return lb * 2ll + 1ll;
}

#ifndef _debug
int main() {
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll res = solve(t1, t2, a1, a2, b1, b2);
    if(res == -1ll)
        cout << "infinity" << endl;
    else
        cout << res << endl;
    return 0;
}
#endif