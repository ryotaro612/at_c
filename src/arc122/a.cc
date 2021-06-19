#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const ll MOD = 1000000007ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> plus(n, 1ll), minus(n, 0ll);
    for(int i = 1; i < n; i++) {
        plus[i] = (plus[i - 1] + minus[i - 1]) % MOD;
        minus[i] = plus[i - 1];
    }

    ll ans = 0ll;
    for(int i = 0; i < n; i++) {
        ll sum = (plus[n - 1 - i] + minus[n - 1 - i]) % MOD;
        ll diff = (plus[i] * sum) % MOD - (minus[i] * plus[n - 1 - i]) % MOD;
        if(diff < 0)
            diff += MOD;
        ans += (a[i] * diff) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
#endif