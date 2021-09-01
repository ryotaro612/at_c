#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll l, ll r) {
    if(r - l >= 2018ll)
        return 0ll;

    ll res = 100000ll;
    for(ll i = l; i < r; i++)
        for(ll j = i + 1ll; j <= r; j++)
            res = min((i * j) % 2019ll, res);

    return res;
}

#ifndef _debug
int main() {
    ll l, r;
    cin >> l >> r;
    cout << solve(l, r);
}
#endif