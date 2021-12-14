#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
ll const MOD = 998244353ll;

ll pow(ll x, ll n, ll mod) {
    x %= mod;
    ll res = 1ll;
    while(n) {
        if(n & 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        n >>= 1;
    }
    return res;
}

ll solve(ll n, ll k, ll m) {
    if(m % MOD == 0)
        return 0ll;
    ll b = pow(k, n, MOD - 1ll);
    return pow(m, b, MOD);
}

#ifdef ONLINE_JUDGE
int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    cout << solve(n, k, m) << endl;
    return 0;
}
#endif