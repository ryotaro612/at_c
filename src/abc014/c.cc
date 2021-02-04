#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(ll n, vector<ll> a, vector<ll> b) {
    ll num = 1000002ll;
    vector<ll> colors(num, 0ll);
    for(ll i = 0ll; i < n; i++) {
        colors[a[i]] += 1ll;
        colors[b[i] + 1ll] -= 1ll;
    }
    for(ll i = 1ll; i < num; i++) {
        colors[i] += colors[i - 1ll];
    }
    ll res = 0ll;
    for(ll i = 0ll; i < num; i++) {
        res = max(res, colors[i]);
    }
    return res;
}
/*
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll i = 0ll; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << solve(n, a, b) << endl;
    return 0;
}
*/