#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll a, ll b) {
    ll res;
    for(ll i = 1ll; i < b; i++) {
        ll cand = (a / i);
        if(a > i * cand)
            cand++;

        if(i * cand >= a && i * (cand + 1) <= b)
            res = i;
    }
    return res;
}

#ifndef _debug
int main() {
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}
#endif