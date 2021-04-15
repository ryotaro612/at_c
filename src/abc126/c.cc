#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ld pres_pow(ld n, ll i) {
    ld res = 1;
    while(i-- > 0)
        res *= n;
    return res;
}

ld solve(ll n, ll k) {
    ld res = 0;
    for(ll i = 1ll; i <= n; i++) {
        ll temp = i, count = 0ll;
        while(temp < k) {
            temp *= 2ll;
            count++;
        }
        res += pres_pow(0.5, count) * (ld)1 / n;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll n, k;
    cin >> n >> k;
    cout << fixed << setprecision(12) << solve(n, k) << endl;
}
#endif