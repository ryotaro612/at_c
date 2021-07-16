#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007ll;

vector<vector<ll>> dp, acc_w, acc_h, acc_d;
int H, W;
void trav(int i, int j, vector<vector<char>> &s) {
    if(dp[i][j] != -1)
        return;
    if(s[i][j] == '#') {
        dp[i][j] = acc_w[i][j] = acc_h[i][j] = acc_d[i][j] = 0ll;
        return;
    }
    if(i == 0) {
        if(j == 0) {
            dp[i][j] = acc_w[i][j] = acc_h[i][j] = acc_d[i][j] = 1ll;
            return;
        } else {
            trav(i, j - 1, s);
            dp[i][j] = acc_w[i][j - 1];
            acc_w[i][j] = acc_w[i][j - 1] + dp[i][j];
            acc_w[i][j] %= MOD;
            acc_d[i][j] = acc_h[i][j] = 1ll;
            return;
        }
    } else {
        if(j == 0) {
            trav(i - 1, j, s);
            dp[i][j] = acc_h[i - 1][j];
            acc_h[i][j] = acc_h[i - 1][j] + dp[i][j];
            acc_h[i][j] %= MOD;
            acc_d[i][j] = acc_w[i][j] = 1ll;
            return;
        } else {
            trav(i, j - 1, s);
            trav(i - 1, j - 1, s);
            trav(i - 1, j, s);
            dp[i][j] = (((acc_h[i - 1][j] + acc_w[i][j - 1]) % MOD) +
                        acc_d[i - 1][j - 1]) %
                       MOD;
            acc_w[i][j] = acc_w[i][j - 1] + dp[i][j];
            acc_w[i][j] %= MOD;
            acc_h[i][j] = acc_h[i - 1][j] + dp[i][j];
            acc_h[i][j] %= MOD;
            acc_d[i][j] = acc_d[i - 1][j - 1] + dp[i][j];
            acc_d[i][j] %= MOD;
            return;
        }
    }
}

void trav2(int h, int w, vector<vector<char>> s) {
    for(int i = 0; i < min(w, h); i++) {
        if(i == 0) {
            dp[i][i] = acc_w[i][i] = acc_h[i][i] = acc_d[i][i] = 1ll;
            for(int j = 1; j < w; j++) {
                if(s[i][j] == '#') {
                    break;
                } else {
                    dp[i][j] = acc_w[i][j - 1];
                    acc_w[i][j] = acc_w[i][j - 1] + dp[i][j];
                    acc_w[i][j] %= MOD;
                    acc_d[i][j] = acc_h[i][j] = dp[i][j];
                }
            }
            for(int j = 1; j < h; j++) {
                if(s[j][i] == '#') {
                    break;
                } else {
                    dp[j][i] = acc_h[j - 1][i];
                    acc_h[j][i] = acc_h[j - 1][i] + dp[j][i];
                    acc_h[j][i] %= MOD;
                    acc_d[j][i] = acc_w[j][i] = dp[j][i];
                }
            }
        } else {
            for(int j = i; j < w; j++) {
                if(s[i][j] == '#')
                    continue;
                dp[i][j] = (((acc_w[i][j - 1] + acc_h[i - 1][j]) % MOD) +
                            acc_d[i - 1][j - 1]) %
                           MOD;
                acc_w[i][j] = acc_w[i][j - 1] + dp[i][j];
                acc_w[i][j] %= MOD;
                acc_h[i][j] = acc_h[i - 1][j] + dp[i][j];
                acc_h[i][j] %= MOD;
                acc_d[i][j] = acc_d[i - 1][j - 1] + dp[i][j];
                acc_d[i][j] %= MOD;
            }
            for(int j = i + 1; j < h; j++) {
                if(s[j][i] == '#')
                    continue;
                dp[j][i] = (((acc_w[j][i - 1] + acc_h[j - 1][i]) % MOD) +
                            acc_d[j - 1][i - 1]) %
                           MOD;
                acc_w[j][i] = acc_w[j][i - 1] + dp[j][i];
                acc_w[j][i] %= MOD;
                acc_h[j][i] = acc_h[j - 1][i] + dp[j][i];
                acc_h[j][i] %= MOD;
                acc_d[j][i] = acc_d[j - 1][i - 1] + dp[j][i];
                acc_d[j][i] %= MOD;
            }
        }
    }
}

ll solve(int h, int w, vector<vector<char>> s) {
    H = h, W = w;
    dp.resize(h);
    acc_h.resize(h);
    acc_w.resize(h);
    acc_d.resize(h);
    fill(dp.begin(), dp.end(), vector<ll>(w, 0ll));
    fill(acc_h.begin(), acc_h.end(), vector<ll>(w, 0ll));
    fill(acc_w.begin(), acc_w.end(), vector<ll>(w, 0ll));
    fill(acc_d.begin(), acc_d.end(), vector<ll>(w, 0ll));
    // trav(h - 1, w - 1, s);
    trav2(h, w, s);
    /*
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << "---- h -----" << endl;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cout << acc_h[i][j] << " ";
        cout << endl;
    }
    cout << "---- w -----" << endl;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cout << acc_w[i][j] << " ";
        cout << endl;
    }
    cout << "---- d -----" << endl;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cout << acc_d[i][j] << " ";
        cout << endl;
    }
    */
    return dp[h - 1][w - 1];
}

#ifndef _LOCAL
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cin >> s[i][j];
    }
    cout << solve(h, w, s) << endl;
    return 0;
}
#endif