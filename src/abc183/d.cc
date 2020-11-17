#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll n, ll w, vector<ll> s, vector<ll> t, vector<ll> p) {

    return "No";
}

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> s(n), t(n), p(n);
    for(ll i = 0; i < n; i++) {
        cin >> s[i] >> t[i] >> p[i];
    }
    cout << solve(n, w, s, t, p);
}