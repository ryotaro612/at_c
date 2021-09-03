#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifndef _debug
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    sort(h.begin(), h.end());
    ll ans = numeric_limits<ll>::max();
    for(int i = 0; i + (k - 1) < n; i++) {
        ans = min(ans, h[i + (k - 1)] - h[i]);
    }
    cout << ans << endl;

    return 0;
}
#endif