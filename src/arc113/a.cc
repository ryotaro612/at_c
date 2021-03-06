#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll check(ll i, ll j, ll k) {
    ll lb = 0ll, ub = k + 1;
    while(ub - lb > 1) {
        ll mid = (lb + ub) / 2ll;
        if(i * j * mid > k)
            ub = mid;
        else
            lb = mid;
    }
    return lb;
}

ll solve(ll k) {
    ll res = 0ll;
    for(ll i = 1ll; i <= k; i++) {
        for(ll j = 1ll; j <= k; j++) {
            if(i * j > k)
                break;
            ll count = check(i, j, k);
            res += count;
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll k;
    cin >> k;
    cout << solve(k) << endl;
}
#endif