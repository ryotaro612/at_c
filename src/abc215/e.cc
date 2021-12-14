#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MOD = 998244353ll;
ll dp[1001][1 << 10][11];
ll solve(int n, string &s) {
    // 10は何もまだ選んでいない
    // dp[0][0][10] = 1;
    // dp[i][j][k]
    // i(1<=i<=n)番目までにjビットで表せる集合を選び、最後に選んだのがk
    for(int i = 0; i <= n; i++) {
        dp[i][0][10] = 1;
    }
    for(int i = 0; i < n; i++) {
        int c = s[i] - 'A';
        for(int j = 0; j < (1 << 10); j++) {
            // すでにどこかでcをとった
            if((1 << c) & j) {
                for(int k = 0; k < 10; k++) {
                    // 今見ているのがc
                    if(k == c) {
                        // とるかとらないか選べる
                        dp[i + 1][j][k] += (dp[i][j][k] * 2ll % MOD);
                        dp[i + 1][j][k] %= MOD;
                    } else { // cを無視しなければならない
                        dp[i + 1][j][k] = dp[i][j][k];
                    }
                }
            } else { // はじめてみた
                for(int k = 0; k < 10; k++) {
                    dp[i + 1][j | (1 << c)][c] += dp[i][j][k];
                    dp[i + 1][j | (1 << c)][c] %= MOD;
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j][k] %= MOD;
                }
            }
        }
        dp[i + 1][1 << c][c] += 1;
        dp[i + 1][1 << c][c] %= MOD;
    }
    ll ans = 0;
    for(int i = 1; i < (1 << 10); i++) {
        for(int j = 0; j < 10; j++) {
            ans += dp[n][i][j];
            ans %= MOD;
        }
    }
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
    return 0;
}
#endif