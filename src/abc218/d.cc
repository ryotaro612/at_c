#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(int n, vector<ll> &x, vector<ll> &y) {

    unordered_map<ll, set<ll>> c;

    rep(i, n) { c[x[i]].insert(y[i]); }
    vector<ll> to_delete;
    for(auto e : c) {
        if(e.second.size() <= 1)
            to_delete.push_back(e.first);
    }
    for(auto d : to_delete)
        c.erase(d);

    vector<ll> xs;
    for(auto e : c) {
        xs.push_back(e.first);
    }
    // cout << keys.size() << endl;
    ll ans = 0ll;
    rep(i, xs.size() - 1) {
        for(int j = i + 1; j < (int)xs.size(); j++) {
            set<int> common;
            set_intersection(c[xs[i]].begin(), c[xs[i]].end(), c[xs[j]].begin(),
                             c[xs[j]].end(), inserter(common, common.end()));
            int common_num = common.size();
            if(common_num > 1)
                ans += common_num * (common_num - 1) / 2;
        }
    }
    return ans;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    cout << solve(n, x, y) << endl;
    return 0;
}
#endif