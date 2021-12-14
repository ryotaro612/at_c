#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    map<ll, bool> mp;
    for(int i = 0; i < n; i++) {
        mp[a[i]] = !mp[a[i]];
    }
    ll ans = 0ll;
    for(auto p : mp) {
        //cout << p.first << " " << p.second << endl;
        if(p.second)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
#endif