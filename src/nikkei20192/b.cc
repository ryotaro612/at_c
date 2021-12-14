#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll MOD = 998244353ll;

ll power(ll a, ll b) {
    ll ans = 1ll;
    for(ll i = 0ll; i < b; i++) {
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

ll solve(ll n, vector<ll> d) {
    vector<ll> count(n, 0);
    ll mx = -1ll;
    for(int i = 0; i < n; i++) {
        count[d[i]]++;
        mx = max(mx, d[i]);
    }
    if(count[0] != 1 || d[0] != 0)
        return 0ll;
    for(int i = 1; i < mx; i++) {
        if(count[i] == 0)
            return 0;
    }
    ll ans = 1ll;
    for(ll i = 0; i < mx; i++) {
        ans *= power(count[i], count[i + 1]);
        ans %= MOD;
    }
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    vector<ll> d(n);
    for(int i = 0; i < n; i++)
        cin >> d[i];
    cout << solve(n, d) << endl;
    return 0;
}
#endif