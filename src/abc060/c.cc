#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> tv(n);
    for(int i = 0; i < n; i++)
        cin >> tv[i];

    ll ans = 0ll;
    for(int i = 0; i < n; i++) {
        if(i < n - 1) {
            ans += min(t, tv[i + 1] - tv[i]);
        } else {
            ans += t;
        }
    }
    cout << ans << endl;
    return 0;
}
#endif