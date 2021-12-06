#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(ll n) {
    ll res = 0ll;
    unordered_set<ll> done;
    for(ll i = 1ll; i * i <= n; i++) {
        res += n / i;
        done.insert(n / i);
    }
    for(ll x = 1ll; x * x < n; x++) {
        if(done.find(x) == done.end()) {
            ll max_x = n / x;
            ll min_x = n / (x + 1ll) + 1ll;
            res += (max_x - min_x + 1ll) * x;
        }
    }

    return res;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif