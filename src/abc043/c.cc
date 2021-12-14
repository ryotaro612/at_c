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
    ll ans = numeric_limits<ll>::max();
    for(ll i = -100; i <= 100; i++) {
        ll temp = 0ll;
        for(auto aa : a) {
            temp += (i - aa) * (i - aa);
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}
#endif