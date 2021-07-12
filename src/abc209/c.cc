#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MOD = 1000000007ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> c(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];
    sort(c.begin(), c.end());
    ll ans = 1ll;
    for(ll i = 0ll; i < n; i++) {
        ans *= (c[i] - i);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
#endif