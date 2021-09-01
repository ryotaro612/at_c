#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007ll;

const ll MAX = 510000ll;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
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

ll solve(ll n, ll k) {
    COMinit();

    if(n <= k + 1ll)
        return com(n + n - 1ll, n - 1ll);
    // n-k-1 1個の数

    ll ans = 0ll;
    // for(ll i = k % 2ll; i <= k; i += 2ll) {
    for(ll i = 0; i <= k; i++) {
        ll delta = (com(n, i) * com(n - 1ll, i) % MOD);
        // cout << delta << endl;
        ans += delta;
        ans %= MOD;
    }
    return ans;
}

#ifndef _debug
int main() {
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    return 0;
}
#endif