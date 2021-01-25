#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// dp[a][b][c] 0からa-1までのカードのうちb個を使って合計をcにできるパターン数
int dp[51][51][2510];
int solve(int n, int a, vector<int> x) {
    for(int limit = 0; limit <= n; limit++) {
        dp[limit][0][0] = 1;
    }
    for(int limit = 1; limit <= n; limit++) {
        for(int num = 1; num <= limit; num++) {
            for(int sum = 0; sum <= 2510; sum++) {
                dp[limit][num][sum + x[limit - 1]] +=
                    dp[limit - 1][num - 1][sum];
            }
        }
    }

    ll res = 0;
    for(int num = 0; num <= n; num++) {
        for(int sum = 0; sum <= 50 * n; sum++) {
            if(sum == a * num) {
                res += dp[n][num][sum];
            }
        }
    }
    return res;
}
/*
int main() {
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << solve(n, a, x) << endl;
}
*/