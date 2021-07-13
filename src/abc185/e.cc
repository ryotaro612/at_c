#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll INF = 1000000000ll;

ll solve(int n, int m, vector<ll> a, vector<ll> b) {
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, INF));

    for(int i = 0; i < n; i++)
        dp[i][0] = n + m;
    for(int i = 0; i < m; i++)
        dp[0][i] = n + m;
    /*
    // 最低保証 a[0]を使わない場合
    dp[1][1] = dp[0][1];
    // a[0]を使う場合
    if(a[0] == b[0]) {
        dp[1][1] = min(dp[1][1], dp[0][0] - 1ll - 1ll);
    } else {
        dp[1][1] = min(dp[1][1], dp[0][0] - 2ll + 1ll);
    }
    // a[0]とb[0]を試すパターンが含まれる
    dp[1][2] = dp[1][1];
    // a[0]とb[1]を試す
    if(a[0] == b[1]) {
        dp[1][2] = min(dp[1][2], dp[0][1] - 2ll);
    } else {
        dp[1][2] = min(dp[1][2], dp[0][1] - 1ll);
    }
    */
    // dp[i][j] a[0]からa[i-1]までを使う。
    //          b[0]からb[j-1]までを使う。
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // a[0]からa[i-2]とb[0]からb[j-1]までを使う場合
            // a[i-1]を使わないときの解
            // dp[i - 1][j];
            // a[i-1]を使うときを考える。
            // a[0]からa[i-1]とb[0]から[j-2]を使う
            // dp[i][j - 1];
            // 残るはa[i-1]とb[j-1]をどちらも使う。
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - 2ll);
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - 1ll);
            }
        }
    }

    return dp[n][m];
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];

    cout << solve(n, m, a, b) << endl;

    return 0;
}
#endif
