#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll n, ll w, vector<ll> s, vector<ll> t, vector<ll> p) {
    vector<ll> a(2 * pow(10, 5) + 1, 0);

    for(ll i = 0; i < n; i++) {
        a[s[i]] += p[i];
        a[t[i]] -= p[i];
    }
    if(a[0] > w) {
        return "No";
    }
    for(ll i = 1; i < (ll)a.size(); i++) {
        a[i] += a[i - 1];
        if(a[i] > w) {
            return "No";
        }
    }

    return "Yes";
}
/*
int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> s(n), t(n), p(n);
    for(ll i = 0; i < n; i++) {
        cin >> s[i] >> t[i] >> p[i];
    }
    cout << solve(n, w, s, t, p);
}
*/