#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, vector<ll> t, vector<ll> a) {
    ll tt = 1, aa = 1;
    for(ll i = 0; i < n; i++) {
        ll x = tt / t[i] + (tt % t[i] == 0 ? 0 : 1);
        ll y = aa / a[i] + (aa % a[i] == 0 ? 0 : 1);
        ll z = max(x, y);
        tt = t[i] * z;
        aa = a[i] * z;
    }

    return tt + aa;
}
/*
int main() {
    ll n;
    cin >> n;
    vector<ll> t(n), a(n);
    for(ll i = 0; i < n; i++) {
        cin >> t[i] >> a[i];
    }
    cout << solve(n, t, a) << endl;
}
*/