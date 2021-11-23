#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(ll n, ll l, ll r) {
    ll res = 0ll;
    for(ll i = 0; i < 63; i++) {
        if(n & (1ll << i)) {
            ll delta = min((ll)(1ll << (i + 1ll)) - 1ll, r) -
                       max((ll)(1ll << i), l) + 1ll;
            if(delta > 0)
                res += delta;
        }
    }
    return res;
}

#ifndef _debug
int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    cout << solve(n, l, r) << endl;
    return 0;
}
#endif
