#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n, ll k) {
    ll res = 0ll;
    for(ll ab = 2ll; ab <= 2ll * n; ab++) {
        ll ab_patterns = min(ab - 1ll, n) - max(ab - n, 1ll) + 1;

        ll cb = ab - k;
        if(cb < 2 || cb > 2ll * n)
            continue;
        ll cb_patterns = min(cb - 1ll, n) - max(cb - n, 1ll) + 1;
        res += ab_patterns * cb_patterns;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
}
#endif