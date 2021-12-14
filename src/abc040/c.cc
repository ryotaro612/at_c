#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const static ll INF = 100000000000000ll;

ll solve(int n, vector<ll> a) {
    if(n == 2) {
        return abs(a[1] - a[0]);
    }
    ll dp[2] = {abs(a[1] - a[0]), 0ll};
    for(int i = 2; i < n; i++) {
        ll temp =
            min(dp[0] + abs(a[i] - a[i - 1]), dp[1] + abs(a[i] - a[i - 2]));
        dp[1] = dp[0];
        dp[0] = temp;

    }
    return dp[0];
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
}
#endif