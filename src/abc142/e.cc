#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = numeric_limits<int>::max() / 2;
const int N = 12;

int solve(int n, int m, vector<int> &a, vector<int> &b,
          vector<vector<int>> &c) {
    vector<vector<int>> dp(m + 1, vector<int>(1 << N, INF));
    dp[0][0] = 0;
    vector<int> bb(m, 0);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < (int)c[i].size(); j++) {
            bb[i] |= (1 << (c[i][j] - 1));
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < (1 << N); j++)
            dp[i][j] = dp[i - 1][j];
        for(int j = 0; j < (1 << N); j++) {
            dp[i][(j | bb[i - 1])] =
                min(dp[i - 1][j] + a[i - 1], dp[i][(j | bb[i - 1])]);
        }
    }
	int ans = dp[m][(1 << n) - 1];
    return ans == INF ? -1 : ans;
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> c(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        for(int j = 0; j < b[i]; j++) {
            cin >> c[i][j];
        }
    }
    cout << solve(n, m, a, b, c) << endl;
    return 0;
}
#endif