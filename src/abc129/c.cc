#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const ll MOD = 1000000007ll;

ll solve(int n, int m, vector<int> a) {
    vector<ll> dp(n + 1, 0ll);
    dp[0] = 1ll;
    set<int> broken;
    for(auto aa : a)
        broken.insert(aa);
    for(int i = 1; i <= n; i++) {
        if(broken.find(i) != broken.end())
            continue;
        dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 0ll);
        dp[i] %= MOD;
    }
    return dp[n];
}

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    cout << solve(n, m, a) << endl;
}
#endif