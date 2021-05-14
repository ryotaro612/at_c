#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    ll a, k;
    cin >> a >> k;

    if(k == 0ll) {
        cout << 2000000000000ll - a << endl;
        return 0;
    }
    ll ub = 2000000000002ll, lb = 0ll;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2ll;
        ll t = a;
        bool ok = false;
        for(ll i = 0; i < mid; i++) {
            t += 1ll + k * t;
            if(t >= 2000000000000ll) {
                ok = true;
                break;
            }
            // cout << t << endl;
        }
        if(ok)
            ub = mid;
        else
            lb = mid;
    }
    cout << ub << endl;
    return 0;
}
#endif