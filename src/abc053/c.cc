#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll x) {
    if(x <= 6ll)
        return 1ll;

    ll a = x / 11ll;
    if(x - a * 11ll <= 0ll)
        return a * 2ll;
    if(x - a * 11ll <= 6ll)
        return a * 2ll + 1ll;

    return a * 2ll + 2ll;
}

#ifndef _debug
int main() {
    ll x;
    cin >> x;
    cout << solve(x) << endl;
    return 0;
}
#endif