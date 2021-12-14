#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll MOD = 1000000007ll;

ll modinv(ll a) {
    long long b = MOD, u = 1, v = 0;
    while(b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= MOD;
    if(u < 0)
        u += MOD;
    return u;
}

ll moddiv(ll a, ll b) { return a * modinv(b) % MOD; }

ll solve(ll n, ll k, vector<ll> a) {
    ll res = 0ll;
    for(int i = 0; i < n; i++) {
        ll all_count = 0ll, partial_count = 0ll;
        for(int j = 0; j < n; j++) {
            if(a[i] > a[j]) {
                all_count++;
                if(j > i)
                    partial_count++;
            }
        }
        // cout << i << " " << partial_count << " " << all_count << endl;
        res += partial_count * k % MOD;
        res %= MOD;
        ll temp = ((moddiv((k * (k - 1) % MOD), 2) % MOD) * all_count) % MOD;
        res += temp;
        res %= MOD;
    }
    return res;
}
#ifdef ONLINE_JUDGE
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, k, a) << endl;
    return 0;
}
#endif
