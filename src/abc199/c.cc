#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc_index(ll n, bool flip, ll index) {
    if(flip == false) {
        return index - 1;
    }
    if(index > n) {
        return index - n - 1;
    } else {
        return index + n - 1;
    }
}

string solve(ll n, string s, ll q, vector<ll> t, vector<ll> a, vector<ll> b) {
    bool flip = false;
    for(ll i = 0ll; i < q; i++) {
        //cout << i - 1 << " " << s << endl;
        if(t[i] == 2) {
            flip = !flip;
            continue;
        }
        ll p_a = calc_index(n, flip, a[i]);
        ll p_b = calc_index(n, flip, b[i]);
        //cout << p_a << " vs " << p_b << endl;
        swap(s[p_a], s[p_b]);
    }
    if(flip == false)
        return s;

    string ans;
    for(int i = 0; i < n; i++)
        ans.push_back(s[n + i]);
    for(int i = 0; i < n; i++)
        ans.push_back(s[i]);
    return ans;
}

#ifndef _debug
int main() {
    ll n, q;
    string s;
    cin >> n >> s >> q;
    vector<ll> t(q), a(q), b(q);
    for(ll i = 0ll; i < q; i++) {
        cin >> t[i] >> a[i] >> b[i];
    }
    cout << solve(n, s, q, t, a, b) << endl;
    return 0;
}
#endif