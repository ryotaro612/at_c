#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const ll MOD = 998244353ll;

ll add(ll a, ll b) { return (a + b) % MOD; }
ll mul(ll a, ll b) { return (a * b) % MOD; }

ll sub(ll a, ll b) {
    ll aa = a % MOD, bb = b % MOD;
    ll res = (aa - bb) % MOD;
    if(res < 0)
        res += MOD;
    return res;
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while(b) {
        ll t = a / b;
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
ll divmod(ll a, ll b) { return mul(a, modinv(b, MOD)); }

ll solve(int n, vector<ll> a) {
    sort(a.begin(), a.end());

    vector<ll> pow2(200001, 1);
    for(int i = 1; i < (int)pow2.size(); i++)
        pow2[i] = mul(2ll, pow2[i - 1]);

    vector<ll> sum(n + 1, 0ll);
    for(int i = 1; i < n + 1; i++)
        sum[i] = add(mul(a[i - 1], pow2[i - 1]), sum[i - 1]);

    ll res = 0ll;
    for(int i = 0; i < n; i++)
        res = add(mul(a[i], a[i]), res);

    for(int i = 0; i < n - 1; i++) {
        res = add(mul(divmod(a[i], pow2[i + 1]), sub(sum[n], sum[i + 1])), res);
    }

    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
#endif