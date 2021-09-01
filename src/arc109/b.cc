#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll find(ll v) {
    ll lb = 0, ub =1414213562ll;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2ll;
        if((mid * (mid + 1ll)) / 2ll > v)
            ub = mid;
        else
            lb = mid;
    }
    return lb;
}

ll solve(ll n) {
    if(n == 1ll)
        return 1ll;
    ll c = find(n + 1ll);
    return n - c + 1;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
#endif