#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(ll n, ll cc, vector<ll> s, vector<ll> t, vector<ll> c) {
    ll len = pow(10, 5) + 2;
    vector<ll> a(len, 0);
    vector<vector<ll>> b(len, vector<ll>(31, 0));
    for(ll i = 0; i < n; i++) {
        b[s[i]][c[i]]++;
    }
    for(ll i = 0; i < n; i++) {
        a[s[i]]++;
        if(b[t[i]][c[i]] > 0) {
            a[t[i]]--;
            b[t[i]][c[i]]--;
        } else {
            a[t[i] + 1]--;
        }
    }
    ll res = a[0];
    for(ll i = 1; i < len; i++) {
        a[i] += a[i - 1];
        res = max(res, a[i]);
    }
    return res;
}
/*
int main() {
    ll n, cc;
    cin >> n >> cc;
    vector<ll> s(n), t(n), c(n);
    for(ll i = 0; i < n; i++) {
        cin >> s[i] >> t[i] >> c[i];
    }
    cout << solve(n, cc, s, t, c);
}
*/