#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, int x, int y, vector<int> &a, vector<int> &b) {
    const int inf = 100000;
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(x + 1, vector<int>(y + 1, inf)));
    for(int i = 0; i <= n; i++)
        dp[i][0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            for(int k = 0; k <= y; k++) {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                dp[i][j][k] = min(
                    dp[i][j][k],
                    dp[i - 1][max(0, j - a[i - 1])][max(0, k - b[i - 1])] + 1);
            }
        }
    }
    return dp[n][x][y] == inf ? -1 : dp[n][x][y];
}

#ifdef ONLINE_JUDGE
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    cout << solve(n, x, y, a, b) << endl;
    return 0;
}
#endif