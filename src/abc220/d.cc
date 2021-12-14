#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const ll MOD = 998244353ll;

vector<ll> solve(int n, vector<ll> &a) {
    vector<vector<ll>> dp(n, vector<ll>(10, 0));
    dp[0][a[0]] = 1ll;

    for(int i = 1; i < n; i++) {
        rep(j, 10) {
            dp[i][(a[i] + j) % 10] += dp[i - 1][j];
            dp[i][(a[i] + j) % 10] %= MOD;
            dp[i][(a[i] * j) % 10] += dp[i - 1][j];
            dp[i][(a[i] * j) % 10] %= MOD;
        }
    }
    vector<ll> res(10);
    rep(i, 10) {
        res[i] = dp[n-1][i];
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> res = solve(n, a);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif