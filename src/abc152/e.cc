#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007ll;

map<ll, int> prime_factor(ll n) {
    map<ll, int> ret;
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1)
        ret[n] = 1;
    return ret;
}
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while(b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if(u < 0)
        u += m;
    return u;
}

ll a_pow(ll x, ll n) {
    ll res = 1ll;
    while(n > 0) {
        if(n & 1) {
            res *= x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}

ll solve(int n, vector<ll> a) {
    if(n == 1) {
        return 1ll;
    }
    map<ll, int> total;
    for(auto aa : a) {
        map<ll, int> mp = prime_factor(aa);
        for(auto p : mp) {
            total[p.first] = max(total[p.first], p.second);
        }
    }
    ll total_lcm = 1ll;
    for(auto t : total) {
        total_lcm *= a_pow(t.first, t.second);
        total_lcm %= MOD;
    }
    ll ans = 0ll;
    for(auto aa : a) {
        ans += total_lcm * modinv(aa, MOD) % MOD;
        ans %= MOD;
    }
    return ans;
    /*
    for(auto aa : a) {
        ans += modinv(aa, MOD);
        ans %= MOD;
    }
    return ans * total_lcm % MOD;
    */
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
    return 0;
}
#endif