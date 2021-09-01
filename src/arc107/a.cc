#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const ll MOD = 998244353ll;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll add(ll a, ll b) { return (a + b) % MOD; }
ll mul(ll a, ll b) { return (a * b) % MOD; }
ll di(ll a, ll b) {
    return a * modinv(b, MOD) % MOD;
}

ll solve(ll a, ll b, ll c) {
    ll cc = di(mul(add(1ll, c), c), 2ll);
    ll bb = di(mul(add(1ll, b), b), 2ll);
    ll aa = di(mul(add(1ll, a), a), 2ll);
    return mul(mul(cc, bb), aa);
}

#ifndef _debug
int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
}
#endif