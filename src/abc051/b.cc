#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll k, ll s) {
    ll res = 0ll;
    for(ll x = 0ll; x <= k; x++) {
        for(ll y = 0ll; y <= k; y++) {
            ll z = s - x - y;
            if(z >= 0ll && z <= k)
                res++;
        }
    }
    return res;
}

#ifndef _debug
int main() {
    ll k, s;
    cin >> k >> s;
    cout << solve(k, s) << endl;
}
#endif