#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    ll res = numeric_limits<ll>::max();
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0ll) {
            ll a = i, b = n / i;
            res = min(res, a - 1 + b - 1);
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif