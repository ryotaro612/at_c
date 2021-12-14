#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int n, string &s) {
    /*
    dp[i][j]
    s[i] == s[j]なら
    dp[i][j] = dp[i+1][j+1]+1;
    */
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    int ans = 0;
    for(int i = n - 2; i >= 0; i--) {
        // iとjは1つ以上間離れている
        for(int j = n - 1; i < j; j--) {
            if(s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            ans = max(ans, min(j - i, dp[i][j]));
            // cout << i << ", " << j << " -> " << dp[i][j] << endl;
        }
    }
    return ans <= 1 ? 0 : ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << solve(n, s) << endl;
    return 0;
}
#endif