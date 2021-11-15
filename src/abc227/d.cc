#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(ll n, ll k, vector<ll> &a) {
    sort(a.begin(), a.end(), greater<ll>());
    ll ub = 1e18 / k, lb = -1ll;
    while(ub - lb > 1ll) {
        ll mid = (ub + lb) / 2ll;
        ll temp = 0ll;
        for(auto e : a) {
            temp += min(mid, e);
        }
        if(temp < mid * k) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    return lb;
}

#ifndef _debug
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    cout << solve(n, k, a) << endl;
    return 0;
}
#endif