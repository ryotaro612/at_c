#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, vector<ll> a) {

    vector<ll> b(a.begin(), a.end()), sum(n + 1, 0);
    sort(b.begin(), b.end());
    for(ll i = 0ll; i < n; i++) {
        sum[i + 1] = b[i] + sum[i];
    }
    ll ans = 1ll;
    for(int i = n - 2; i >= 0; i--) {
        if(sum[i + 1] * 2ll >= b[i + 1])
            ans++;
        else
            break;
    }

    return ans;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, a) << endl;
    return 0;
}
#endif