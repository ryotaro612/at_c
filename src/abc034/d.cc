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
        for(int j = 0; j <= k; j++) {
            double current_salt = (((double)w[i] * (double)p[i]) / (double)100);
            double salt = dp[i - 1][j - 1].second + current_salt;
            ll salty = dp[i - 1][j - 1].first + w[i];
            if(salt / (double)salty >=
               (double)dp[i - 1][j].second / (double)dp[i - 1][j].first) {
                dp[i][j] = salty_water(salty, salt);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
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