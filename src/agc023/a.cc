#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    map<ll, ll> mp;
    mp[0ll]++;
    ll sum = 0ll;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        mp[sum]++;
    }
    ll ans = 0ll;
    for(auto p : mp) {
        if(p.second >= 2) {
            ans += (p.second * (p.second - 1) / 2ll);
        }
    }
    cout << ans << endl;
    return 0;
}
#endif