#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n) {
    ll res = 100000000000ll;
    for(ll x = 1ll; x <= n; x++) {
        ll y = n / x;
        res = min(res, abs(x - y) + (n - x * y));
    }
    return res;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif