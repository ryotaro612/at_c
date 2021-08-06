#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[101][2][5];

ll solve(string s, ll k) {

    int n = s.size();
    ll c = s[0] - '0';
    dp[1][1][0] = 1ll;
    dp[1][1][1] = c - 1ll;
    dp[1][0][1] = 1ll;

    for(int i = 1; i < n; i++) {
        c = s[i] - '0';
        for(int j = 0; j <= k; j++) {
            // dp[i+1][0][j]
            if(c == 0) {
                dp[i + 1][0][j] = dp[i][0][j];
            } else { // c > 0
                dp[i + 1][0][j] = j > 0ll ? dp[i][0][j - 1] : 0ll;
            }
            // dp[i+1][1][j]
            if(c == 0) {
                dp[i + 1][1][j] = dp[i][1][j];
                if(j > 0)
                    dp[i + 1][1][j] += dp[i][1][j - 1] * 9ll;
                else
                    dp[i + 1][1][1] += 9ll;
            } else { // c > 0
                // 1以上の値にする
                dp[i + 1][1][j] = j == 0 ? 0ll : (dp[i][0][j - 1] * (c - 1ll));
                // 0にする
                dp[i + 1][1][j] += dp[i][0][j];
                // 0にする
                dp[i + 1][1][j] +=
                    dp[i][1][j] + (j == 0 ? 0ll : dp[i][1][j - 1] * 9ll);
            }
        }
    }
    // 8 0 は0
    /*
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            cout << "dp[" << i << "][" << 0 << "][" << j << "] -> "
                 << dp[i][0][j] << endl;
            cout << "dp[" << i << "][" << 1 << "][" << j << "] -> "
                 << dp[i][1][j] << endl;
        }
    }
    */
    return dp[n][0][k] + dp[n][1][k];
}

#ifndef _LOCAL
int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << solve(s, k) << endl;
    return 0;
}
#endif
/*
dp[0][0][0] -> 0
dp[0][1][0] -> 0
dp[0][0][1] -> 0
dp[0][1][1] -> 0
dp[1][0][0] -> 0
dp[1][1][0] -> 1
dp[1][0][1] -> 1
dp[1][1][1] -> 0
dp[2][0][0] -> 0
dp[2][1][0] -> 1
dp[2][0][1] -> 1
dp[2][1][1] -> 9
dp[3][0][0] -> 0
dp[3][1][0] -> 1
dp[3][0][1] -> 1
dp[3][1][1] -> 18
*/