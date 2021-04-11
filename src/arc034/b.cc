#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(ll n) {
    string s = to_string(n);
    ll res = 0ll;
    for(auto ss : s) {
        res += ss - '0';
    }
    return res;
}

vector<ll> solve(ll n) {
    vector<ll> res;
    for(ll i = max(0ll, n - 1000ll); i <= n; i++) {
        if(i + sum(i) == n)
            res.push_back(i);
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    auto res = solve(n);
    cout << res.size() << endl;
    for(auto r : res)
        cout << r << endl;
}
#endif