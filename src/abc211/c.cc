#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll MOD = 1000000007ll;

ll dp[100001][9];

#ifdef ONLINE_JUDGE
int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    // dp[i][j] i番目の文字を見終わったときまでにj個の文字を見たパターン
    dp[0][0] = 1ll;
    string chokudai = "chokudai";
    for(int i = 0; i < n; i++) {
        char c = s[i];
        bool found = false;
        for(int j = 0; j < 8; j++) {
            if(c == chokudai[j]) {
                dp[i + 1][j + 1] = dp[i][j];
            }
        }
        for(int j = 0; j < 9; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
        }
    }
    cout << dp[n][8] << endl;

    return 0;
}
#endif