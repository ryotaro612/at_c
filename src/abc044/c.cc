#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// dp[a][b][c] 0からa-1までのカードのうちb個を使って合計をcにできるパターン数
static const ll LIMIT = 51;
static const ll SUM = 2510;
ll solve(ll n, ll a, vector<ll> x) {
    vector<vector<vector<ll>>> dp(
        LIMIT, vector<vector<ll>>(LIMIT, vector<ll>(SUM, 0)));

    for(ll limit = 0; limit <= n; limit++) {
        dp[limit][0][0] = 1;
    }
    for(ll limit = 1; limit <= n; limit++) {
        for(ll num = 1; num <= limit; num++) {
            for(ll sum = 0; sum < SUM; sum++) {
                dp[limit][num][sum] += dp[limit - 1][num][sum];
                if(sum + x[limit - 1] < SUM) {
                    dp[limit][num][sum + x[limit - 1]] +=
                        dp[limit - 1][num - 1][sum];
                }
            }
        }
    }

    ll res = 0;
    for(ll num = 1; num <= n; num++) {
        for(ll sum = 0; sum <= 50 * n; sum++) {
            if(sum == a * num) {
                res += dp[n][num][sum];
            }
        }
    }
    return res;
}
/*
int main() {
    ll n, a;
    cin >> n >> a;
    vector<ll> x(n);
    for(ll i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << solve(n, a, x) << endl;
}
*/
