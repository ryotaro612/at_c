#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<bool>> used;

ll solve(int n, vector<ll> t) {
    sort(t.begin(), t.end(), greater<ll>());
    ll sum = 0ll;
    for(auto tt : t)
        sum += tt;
    ll top = (sum + 1ll) / 2ll;
    used = vector<vector<bool>>(top + 1, vector<bool>(n, false));
    vector<ll> dp(top + 1, 0ll);
    for(int i = 0; i <= top; i++) {
        int used_i = -1;

        for(int j = 0; j < n; j++) {
            if(i >= t[j] && !used[i - t[j]][j] && dp[i - t[j]] + t[j] <= i &&
               dp[i] < dp[i - t[j]] + t[j]) {
                dp[i] = dp[i - t[j]] + t[j];
                used_i = j;
            }
        }
        if(used_i != -1) {
            used[i][used_i] = true;
        }
    }
    /*
    for(int i = 0; i < (int)dp.size(); i++)
        cout << i << " -> " << dp[i] << endl;
        */
    return max(dp[top], sum - dp[top]);
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    for(int i = 0; i < n; i++)
        cin >> t[i];
    cout << solve(n, t) << endl;
    return 0;
}
#endif