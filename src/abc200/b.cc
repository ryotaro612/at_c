#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k) {
    ll ans = n;
    for(int i = 0; i < k; i++) {
        if(ans % 200ll == 0) {
            ans /= 200ll;
            continue;
        }
        ans *= 1000;
        ans += 200;
    }
    return ans;
}

#ifndef _debug
int main() {
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
}
#endif
