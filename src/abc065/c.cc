#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const ll MOD = 1000000007ll;

ll fact(ll n) {
    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

ll solve(ll n, ll m) {
    if(abs(n - m) >= 2)
        return 0;
    ll mul = fact(n) * fact(m) % MOD;
    if(abs(n - m) == 1)
        return mul;
    return 2 * mul % MOD;
}

#ifndef _LOCAL
int main() {
    ll n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    return 0;
}
#endif