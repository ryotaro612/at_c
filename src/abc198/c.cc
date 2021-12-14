#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll safe_sqrt(ll n) {
    ll res = 1;
    while((res * res) != n)
        res++;
    return res;
}

ll solve(ll r, ll x, ll y) {
    ll d = x * x + y * y;
    ll r2 = r * r;

    if(x == 0ll && y == 0ll)
        return 0ll;
    if(d == r2)
        return 1ll;
    if(d < r2)
        return 2ll;
/*
    if(d % r2 == 0ll) {
        return safe_sqrt(d / r2);
    }
    */

    ll cand = (ld)sqrt((ld)d / (ld)r2);
    for(ll i = max(cand - 20ll, 0ll);; i++) {
        if(d <= i * i * r2) {
            cand = i;
            break;
        }
    }
    return cand;

    /*

    ll lb = 0ll, ub = 1000000000ll;
    while(ub - lb > 1) {
        ll mid = (lb + ub) / 2ll;
        if(d <= mid * mid * r2) {
            ub = mid;
        } else
            lb = mid;
    }
    return ub;
    */
}

#ifdef ONLINE_JUDGE
int main() {
    ll r, x, y;
    cin >> r >> x >> y;
    cout << solve(r, x, y) << endl;
    return 0;
}
#endif