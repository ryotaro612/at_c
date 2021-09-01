#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    map<ll, ll> count;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(auto aa : a) {
        count[aa]++;
        count[aa + 1]++;
        count[aa - 1]++;
    }
    ll ans = 0ll;
    for(auto c : count) {
        ans = max(ans, c.second);
    }
    cout << ans << endl;
    return 0;
}
#endif