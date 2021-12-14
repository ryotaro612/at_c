#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007ll;

const ll MAX = 510000;

ll fac[MAX], finv[MAX], inv[MAX];

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

// 二項係数計算
ll COM(ll n, ll k) {
    if(n < k)
        return 0;
    if(n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll solve(int n, int k, vector<ll> &a) {
    COMinit();
    sort(a.begin(), a.end());
    ll ans = 0ll;
    for(int i = 0; i < n; i++) {
        if(k <= i + 1) {
            ans += a[i] * COM(i, k - 1);
            ans %= MOD;
        }
        if(i <= n - k) {
			//cout << "index " << i << " -> " << n-i-1 << ", " << k-1 << endl;
            ll temp = a[i] * COM(n - i - 1, k - 1);
            temp %= MOD;
            ans -= temp;
            if(ans < 0)
                ans += MOD;
        }
    }
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, k, a) << endl;
    return 0;
}
#endif