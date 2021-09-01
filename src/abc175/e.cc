#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[3001][3001][4];
ll item[3001][3001];

ll max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
ll max4(ll a, ll b, ll c, ll d) { return max(a, max(b, max(c, d))); }
ll max5(ll a, ll b, ll c, ll d, ll e) {
    return max(a, max(b, max(c, max(d, e))));
}

ll solve(int r, int c, int k, vector<int> &rv, vector<int> &cv, vector<ll> &v) {
    for(int i = 0; i < k; i++)
        item[rv[i]][cv[i]] = v[i];

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(item[i][j] == 0ll) {
                dp[i][j][0] =
                    max5(dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2],
                         dp[i - 1][j][3], dp[i][j - 1][0]);
                dp[i][j][1] = dp[i][j - 1][1];
                dp[i][j][2] = dp[i][j - 1][2];
                dp[i][j][3] = dp[i][j - 1][3];
            } else { // アイテムがある
                dp[i][j][0] =
                    max5(dp[i][j - 1][0], dp[i - 1][j][0], dp[i - 1][j][1],
                         dp[i - 1][j][2], dp[i - 1][j][3]);
                dp[i][j][1] =
                    max(dp[i][j - 1][1],
                        max5(dp[i][j - 1][0], dp[i - 1][j][0], dp[i - 1][j][1],
                             dp[i - 1][j][2], dp[i - 1][j][3]) +
                            item[i][j]);

                dp[i][j][2] =
                    max(dp[i][j - 1][2], dp[i][j - 1][1] + item[i][j]);
                dp[i][j][3] =
                    max(dp[i][j - 1][3], dp[i][j - 1][2] + item[i][j]);
            }
        }
    }

    return max4(dp[r][c][3], dp[r][c][2], dp[r][c][1], dp[r][c][0]);
}

#ifndef _debug
int main() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<int> rv(k), cv(k);
    vector<ll> v(k);
    for(int i = 0; i < k; i++) {
        cin >> rv[i] >> cv[i] >> v[i];
    }

    cout << solve(r, c, k, rv, cv, v) << endl;
    /*
cout << " ====== " << endl;
for(int a = 0; a < 4; a++) {
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << dp[i][j][a] << " ";
        }
        cout << endl;
    }
    cout << "------" << endl;
}
    */

    return 0;
}
#endif