#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const ll MOD = 998244353ll;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ll d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
}

ll inv(ll a) {
    ll x, y;
    extgcd(a, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}

ll comp(vector<ll> &a) {
    map<ll, ll> mem;
    for(auto e : a)
        mem[e] = 0;
    ll counter = 0;
    for(auto &p : mem)
        p.second = counter++;
    for(auto &e : a) {
        e = mem[e];
    }
    return counter;
}

class Bit {
  public:
    Bit(ll n) : n(n) { bit = vector<ll>(n + 1, 0ll); }

    void add(int index, ll val) {
        index++;
        while(index <= n) {
            bit[index] += val;
            bit[index] %= MOD;
            index += index & -index;
        }
    }
    ll sum(int index) {
        index++;
        ll res = 0ll;
        while(index > 0) {
            res += bit[index];
            res %= MOD;
            index -= index & -index;
        }
        return res;
    }

  private:
    ll n;
    vector<ll> bit;
};

ll mpow(ll x, ll n) {
    ll res = 1ll;
    while(n > 0) {
        if(n & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    return res;
}

ll solve(int n, vector<ll> &a) {
    ll max_a_p1 = comp(a);
    Bit bit(max_a_p1);
    ll ans = 0ll;
    rep(i, n) {
        if(i > 0) {
            ans += bit.sum(a[i]) * mpow(2ll, i - 1) % MOD;
            ans %= MOD;
        }
        bit.add(a[i], inv(mpow(2ll, i)));
    }
    return ans;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    cout << solve(n, a) << endl;
    return 0;
}
#endif