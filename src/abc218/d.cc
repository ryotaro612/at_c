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

    vector<ll> keys;
    for(auto e : c) {
        keys.push_back(e.first);
    }
	//cout << keys.size() << endl;
    ll ans = 0ll;
    rep(i, keys.size() - 1) {
        for(int j = i + 1; j < (int)keys.size(); j++) {
            for(auto e : c[i]) {
                if(c[j].find(e) != c[j].end())
                    ans++;
            }
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