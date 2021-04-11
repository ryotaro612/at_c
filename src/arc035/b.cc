#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const ll MOD = 1000000007ll;

ll mod_fact(ll n) {
    ll res = n;
    while(--n > 0) {
        res *= n;
        res %= MOD;
    }
    return res;
}

pair<ll, ll> solve(int n, vector<ll> t) {
    map<ll, ll> count;
    for(auto tt : t)
        count[tt] = count[tt] + 1;
    vector<pair<ll, ll>> lst;
    for(auto c : count)
        lst.push_back(make_pair(c.first, c.second));
    sort(lst.begin(), lst.end());
    /*
    cout << "--" << endl;
    for(auto l : lst) {
        cout << l.first << " " << l.second << endl;
    }
    cout << "--" << endl;
    */
    ll penalty = 0ll, patterns = 1ll, elapsed_time = 0ll;
    for(auto p : lst) {
        patterns *= mod_fact(p.second);
        patterns %= MOD;
        for(int i = 0; i < p.second; i++) {
            penalty += (p.first + elapsed_time);
            elapsed_time += p.first;
        }
    }
    return make_pair(penalty, patterns);
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    for(int i = 0; i < n; i++)
        cin >> t[i];
    auto res = solve(n, t);
    cout << res.first << endl;
    cout << res.second << endl;
}
#endif