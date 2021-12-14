#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353ll;
const ll MAX = 200001;

long long fac[MAX], finv[MAX], inv[MAX];

ll mod_pow(ll x, ll n) {
    ll res = 1ll;
    while(n > 0ll) {
        if(n & 1ll) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    return res;
}

void com_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long com(int n, int k) {
    if(n < k)
        return 0;
    if(n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll sub(ll n, ll m, ll same_num) {
    ll res = (m * mod_pow(m - 1ll, n - 1ll - same_num)) % MOD;
    // cout << res << endl;
    res *= com(n - 1ll, same_num);
    res %= MOD;

    return res;
}

ll solve(ll n, ll m, ll k) {
    com_init();

    ll ans = 0ll;
    for(ll i = 0; i <= k; i++) {
        ans += sub(n, m, i);
        ans %= MOD;
    }
    // cout << (100ll * mod_pow(99ll, 99ll)) % MOD << endl;
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    cout << solve(n, m, k) << endl;

    return 0;
}
#endif