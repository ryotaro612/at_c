#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(ll n, ll d, ll k, vector<ll> l, vector<ll> r, vector<ll> s,
                 vector<ll> t) {
    vector<ll> res(k);
    for(ll i = 0ll; i < k; i++) {
        for(ll j = 0ll; j < d; j++) {
            if(l[j] <= s[i] && s[i] <= r[j]) {
                if(s[i] < t[i]) {
                    s[i] = min(r[j], t[i]);
                } else if(s[i] > t[i]) {
                    s[i] = max(l[j], t[i]);
                }
                if(s[i] == t[i]) {
                    res[i] = j + 1ll;
                    break;
                }
            }
        }
    }
    return res;
}
/*
int main() {
    ll n, d, k;
    cin >> n >> d >> k;
    vector<ll> l(d), r(d), s(k), t(k);
    for(int i = 0; i < d; i++) {
        cin >> l[i] >> r[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> s[i] >> t[i];
    }
    vector<ll> res = solve(n, d, k, l, r, s, t);
    for(int i = 0; i < k; i++) {
        cout << res[i] << endl;
    }
}
*/