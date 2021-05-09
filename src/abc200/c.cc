#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a) {
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[a[i] % 200ll]++;
    }
    ll ans = 0ll;
    for(auto p : mp) {
        if(p.second > 1) {
            ans += p.second * (p.second - 1ll) / 2ll;
        }
    }
    return ans;
}

#ifndef _LOCAL
int main() {

    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
#endif
