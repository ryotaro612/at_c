#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
static const ll INF = 10000000000ll;
int solve(ll h, ll n, vector<ll> a, vector<ll> b) {
    vector<ll> dp(10010, INF);
    dp[0] = 0ll;
    for(ll i = 0ll; i <= h; i++) {
        if(dp[i] >= INF)
            continue;
        for(ll j = 0ll; j < n; j++) {
            ll dest = min(i + a[j], h);
            // cout << "dest: " << dest << " " << dp[i] + b[j] << endl;
            dp[dest] = min(dp[i] + b[j], dp[dest]);
        }
    }
    /*
        for(int i = 0; i <= h; i++)
            cout << i << " -> " << dp[i] << endl;
            */
    return dp[h];
}

#ifdef ONLINE_JUDGE
int main() {
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    cout << solve(h, n, a, b) << endl;
}
#endif