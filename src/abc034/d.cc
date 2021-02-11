#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll, double> salty_water;

double solve(int n, int k, vector<ll> w, vector<int> p) {
    vector<vector<salty_water>> dp(n + 1, vector<salty_water>(k + 1));
    dp[0][0] = salty_water(0, 0);
    for(int i = 0; i <= k; i++) {
        dp[0][i] = salty_water(0ll, 0);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k && j <= i; j++) {
            cout << "i: " << i << " j: " << j << endl;
            double current_salt =
                (((double)w[i - 1] * (double)p[i - 1]) / (double)100);
            if(j == 1) {
                if(i == 1 || current_salt / w[i - 1] >
                                 dp[i - 1][j].second / dp[i - 1][j].first) {
                    dp[i][j] = salty_water(w[i - 1], current_salt);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
                continue;
            }

            double salt = dp[i - 1][j - 1].second + current_salt;
            ll salty = dp[i - 1][j - 1].first + w[i - 1];
            cout << "expr: salty_water: " << salty << " salt: " << salt << endl;
            if(j == i || salt / (double)salty >=
               (double)dp[i - 1][j].second / (double)dp[i - 1][j].first) {
                dp[i][j] = salty_water(salty, salt);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            cout << "salty_water: " << dp[i][j].first
                 << " salt: " << dp[i][j].second << endl;
        }
    }
    cout << "##### " << ((double)dp[n][k].second / (double)dp[n][k].first) * 100
         << endl;
    return ((double)dp[n][k].second / (double)dp[n][k].first) * 100;
}
/*
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> w(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> p[i];
    }
    cout << fixed << setprecision(12) << solve(n, k, w, p) << endl;
}
*/