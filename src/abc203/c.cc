#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(ll i = 0ll; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    map<ll, ll> mp;

    for(ll i = 0ll; i < n; i++) {
        mp[a[i]] += b[i];
    }
    vector<pair<ll, ll>> friends;
    for(auto p : mp) {
        friends.push_back(make_pair(p.first, p.second));
    }
    sort(friends.begin(), friends.end());

    ll ans = 0ll;
    int offset = 0;
    while(true) {
        if(k == 0ll) {
            break;
        }
        ans += k;
        k = 0ll;
        for(; offset < (int)friends.size();) {
            if(ans >= friends[offset].first) {
                k += friends[offset].second;
                offset++;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
#endif