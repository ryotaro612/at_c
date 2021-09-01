#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll keta(int n) {
    ll res = 1ll;
    while(n >= 10) {
        n /= 10;
        res++;
    }
    return res;
}

ll solve(ll a, ll b, ll x) {
    ll lb = 0ll, ub = 1000000000ll + 1ll;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2ll;
        ll cost = a * mid + b * keta(mid);
        if(cost > x)
            ub = mid;
        else // cost <= x
            lb = mid;
    }
    return lb;
}

#ifndef _debug
int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    cout << solve(a, b, x) << endl;
}
#endif