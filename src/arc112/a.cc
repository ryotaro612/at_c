#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(ll t, vector<ll> l, vector<ll> r) {
    vector<ll> res(t);

    for(ll i = 0ll; i < t; i++) {
        //cout << t << " -> " << i  << endl;
        ll count = max(r[i] - 2ll * l[i] + 1ll, 0ll);
        //cout << "count: " << count << endl;
        res[i] = count * (count + 1ll) / 2ll;
    }
    return res;
}
/*
int main() {
    ll t;
    cin >> t;
    vector<ll> l(t), r(t);
    for(int i = 0; i < t; i++) {
        cin >> l[i] >> r[i];
    }
    vector<ll> res =  solve(t, l, r);
    for(ll i=0ll;i<t; i++) {
        cout << res[i] << endl;
    }
    return 0;
}
*/