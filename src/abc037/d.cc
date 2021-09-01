#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MOD = 1000000007ll;
int h, w;

vector<vector<ll>> dp, a;

ll dfs(int i, int j) {
    if(dp[i][j] != -1ll)
        return dp[i][j];
    ll ans = 1ll;

    if(i > 0 && a[i][j] < a[i - 1][j]) {
        ans += dfs(i - 1, j);
        ans %= MOD;
    }
    if(j < w - 1 && a[i][j] < a[i][j + 1]) {
        ans += dfs(i, j + 1);
        ans %= MOD;
    }
    if(i < h - 1 && a[i][j] < a[i + 1][j]) {
        ans += dfs(i + 1, j);
        ans %= MOD;
    }
    if(0 < j && a[i][j] < a[i][j - 1]) {
        ans += dfs(i, j - 1);
        ans %= MOD;
    }
    return dp[i][j] = ans;
}

#ifndef _debug
int main() {
    cin >> h >> w;
    a.resize(h);
    for(int i = 0; i < h; i++) {
        a[i] = vector<ll>(w);
        for(int j = 0; j < w; j++)
            cin >> a[i][j];
    }

    dp.resize(h);
    for(int i = 0; i < h; i++) {
        dp[i] = vector<ll>(w);
        for(int j = 0; j < w; j++)
            dp[i][j] = -1ll;
    }

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            dfs(i, j);

    ll ans = 0ll;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++) {
            ans += dp[i][j];
            ans %= MOD;
        }
    cout << ans << endl;

    return 0;
}
#endif