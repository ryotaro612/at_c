#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/**
 * 返り値: a と b の最大公約数
 * ax + by = gcd(a, b) を満たす (x, y) が格納される
 */
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll solve(ll n, ll s, ll k) {
    ll x, y, g;
    g = extGCD(n, k, x, y);
    if(s % g != 0ll)
        return -1ll;
    ll temp = -y * (s / g);
    if(y < 0) {
        return temp % (n / g);
    }
    return temp % (n / g) + (n / g);
}

#ifndef _LOCAL
int main() {
    int t;
    cin >> t;
    vector<ll> n(t), s(t), k(t);
    for(int i = 0; i < t; i++)
        cin >> n[i] >> s[i] >> k[i];

    for(int i = 0; i < t; i++)
        cout << solve(n[i], s[i], k[i]) << endl;

    return 0;
}
#endif