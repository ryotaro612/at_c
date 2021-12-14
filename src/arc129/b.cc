#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

vector<ll> solve(int n, vector<ll> &l, vector<ll> &r) {
    vector<ll> res;
    ll l_edge = -1e10, r_edge = 1e10;
    rep(i, n) {
        l_edge = max(l[i], l_edge);
        r_edge = min(r[i], r_edge);
        if(l_edge <= r_edge)
            res.push_back(0ll);
        else { // r_edge < l_edge
            res.push_back((l_edge - r_edge + 1ll) / 2ll);
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    vector<ll> res = solve(n, l, r);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif