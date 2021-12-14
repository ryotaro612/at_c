#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[3001][3001][2];

int solve(int n, int t, vector<int> &a, vector<int> &b) {

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3000; j++) {
            dp[i][j][0] = dp[i - 1][j][0];
            if(j >= a[i - 1])
                dp[i][j][0] =
                    max(dp[i - 1][j - a[i - 1]][0] + b[i - 1], dp[i][j][0]);

            dp[i][j][1] = dp[i - 1][j][1];
            if(j >= a[i - 1])
                dp[i][j][1] =
                    max(dp[i - 1][j - a[i - 1]][1] + b[i - 1], dp[i][j][1]);

			dp[i][j][1] = max(dp[i-1][j-1][0] + b[i-1], dp[i][j][1]);
        }
    }
    return max(dp[n][t][0], dp[n][t][1]);
}

#ifdef ONLINE_JUDGE
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    cout << solve(n, t, a, b) << endl;
    return 0;
}
#endif