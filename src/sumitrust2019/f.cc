#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(ll t1, ll t2, ll a1, ll a2, ll b1, ll b2) {
    if(t1 * a1 + t2 * a2 == b1 * t1 + b2 * t2)
        return -1ll;
    if(b1 < a1 && a2 < b2) {
        swap(a1, b1);
        swap(a2, b2);
    } else if(!(a1 < b1 && b2 < a2)) {
        return 0ll;
    }
    // ll unit_dist = a1 * t1 + a2 * t2 - b1 * t1 - b2 * t2;
    // x * unit_dist <= (b1 - a1) * t1;
    ll ub = numeric_limits<ll>::max() / (2ll * (b1 * t1 + b2 * t2)), lb = -1ll;
    while(ub - lb > 1ll) {
        ll mid = (ub + lb) / 2ll;
        ll dist_a = (a1 * t1 + a2 * t2) * mid,
           dist_b = (b1 * t1 + b2 * t2) * mid;
        ll dist = dist_a - dist_b;
        //cout << "mid: " << mid << " dist " << dist << endl;
        if(dist <= (b1 - a1) * t1 ||
           (0 <= (b1 - a1) * t1 - dist &&
            (b1 - a1) * t1 - dist <= t2 * (a2 - b2))) {
            lb = mid;
        } else {
            ub = mid;
        }
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