#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// dp[a][b][c] 0からa-1までのカードのうちb個を使って合計をcにできるパターン数
static const int LIMIT = 41; // 51
static const int SUM = 2510; // 2510
// int dp[LIMIT][LIMIT][SUM];
int solve(int n, int a, vector<int> x) {
    vector<vector<vector<int>>> dp(
        LIMIT, vector<vector<int>>(LIMIT, vector<int>(SUM, 0)));

    for(int limit = 0; limit <= n; limit++) {
        dp[limit][0][0] = 1;
    }
    for(int limit = 1; limit <= n; limit++) {
        for(int num = 1; num <= limit; num++) {
            for(int sum = 0; sum < SUM; sum++) {
                dp[limit][num][sum] += dp[limit - 1][num][sum];
                dp[limit][num][sum + x[limit - 1]] +=
                    dp[limit - 1][num - 1][sum];
            }
        }
    }
    /*
    for(int limit = 0; limit < LIMIT; limit++) {
        for(int num = 0; num <= limit; num++) {
            for(int sum = 0; sum < SUM; sum++) {
                cout << limit << " " << num << " " << sum << " -> "
                     << dp[limit][num][sum] << endl;
            }
        }
    }
    */
    ll res = 0;
    for(int num = 1; num <= n; num++) {
        for(int sum = 0; sum <= 50 * n; sum++) { // fix sum TODO 50 * n
            if(sum == a * num) {
                // cout << "add  dp[" << n << "][" << num << "][" << sum << "]
                // -> " << dp[n][num][sum] << endl;
                res += dp[n][num][sum];
            }
        }
    }
    return res;
}
int main() {
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << solve(n, a, x) << endl;
}

/*
dp[2][1][7,9] = 1
dp[2][2][16] = 1
dp[3][1][7,8,9] = 1
dp[3][2][15, 16, 17] = 1
dp[3][3][24] = 1
dp[4][0][0] = 1
dp[4][1][7, 8] = 1, dp[4][1][9] = 2
dp[4][2][15] = 1, dp[4][2][16] = 2, dp[4][2][17] =2, dp[4][2][18] =1
dp[4][3][24] = 2, dp[4][3][25, 26] = 1
dp[4][4][33] = 1
*/