#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
ll const MOD = 1000000007ll;

ll solve(string l) {
    int n = l.size();
    vector<vector<int>> dp(2, vector<int>(n, 0));
    rep(i, n) {
        if(i == 0) {
			// 1 はちょうど
            dp[1][0] = 2ll;
            dp[0][0] = 1ll;
        } else {
            if(l[i] == '0') {
                dp[1][i] = dp[1][i - 1];
                dp[0][i] = (dp[0][i - 1] * 3ll) % MOD;
            } else { // 1
                dp[1][i] = (dp[1][i - 1] * 2ll) % MOD;
                dp[0][i] = dp[1][i - 1] + (dp[0][i - 1] * 3ll) % MOD;
            }
        }
    }
    return (dp[0][n - 1] + dp[1][n - 1]) % MOD;
}

#ifndef _debug
int main() {
    string l;
    cin >> l;
    cout << solve(l) << endl;
    return 0;
}
#endif