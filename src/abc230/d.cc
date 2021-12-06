#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, ll d, vector<ll> &l, vector<ll> &r) {
    vector<pair<ll, ll>> rl(n);
    rep(i, n) rl[i] = {r[i], l[i]};
    sort(rl.begin(), rl.end());
    int res = 0;
    ll current = 0ll;
    for(int i = 0; i < n; i++) {
        ll r = rl[i].first, l = rl[i].second;
        if(current < l) {
            res++;
            current = r + d - 1ll;
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> lv(n), rv(n);
    rep(i, n) cin >> lv[i] >> rv[i];
    cout << solve(n, d, lv, rv) << endl;

    return 0;
}
#endif
