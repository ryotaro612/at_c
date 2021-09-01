#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    ll r, g, b, n, ans = 0ll;
    cin >> r >> g >> b >> n;

    for(ll x = 0ll; x <= 3000ll; x++) {
        for(ll y = 0ll; y <= 3000ll; y++) {
            ll z_cand = n - x * r - g * y;
            if(z_cand < 0ll || z_cand % b != 0ll)
                continue;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
#endif
