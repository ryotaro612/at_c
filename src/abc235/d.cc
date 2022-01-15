#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const ll INF = 1 << 30;
const ll MX = 1000000;
/*
void rec(int x, int a, vector<int> &dp) {
    if(x % a == 0) {
        int next_x = x / a;
        if(dp[x] + 1 < dp[next_x]) {
            dp[next_x] = dp[x] + 1;
            rec(next_x, a, dp);
        }
    }
    if(x >= 10 && x % 10 != 0) {
        // cout << " x :" << x << endl;
        string s = to_string(x);
        char c = s[0];
        string next_xs = string(s.begin() + 1, s.end());
        next_xs.push_back(c);
        // cout << " next_xs: " << next_xs << endl;
        int next_x = stoi(next_xs);
        if(next_x < MX && dp[x] + 1 < dp[next_x]) {
            dp[next_x] = dp[x] + 1;
            rec(next_x, a, dp);
        }
    }
}
int solve(int a, int n) {
    vector<int> dp(MX, INF);
    dp[n] = 0;

    rec(n, a, dp);
    if(dp[1] == INF)
        return -1;
    else
        return dp[1];
}
*/

void rec2(ll x, ll a, vector<ll> &dp) {
    if(x * a < MX) {
        if(dp[x] + 1 < dp[x * a]) {
            dp[x * a] = dp[x] + 1;
            rec2(x*a, a, dp);
        }
    }
    if(x >= 10 && x % 10 != 0) {
        string s = to_string(x);
        char c = s[s.size() - 1];
        s.pop_back();
        string next_xs = string(1, c) + s;
        ll next_x = stoll(next_xs);
        if(next_x < MX && dp[x] + 1 < dp[next_x]) {
            dp[next_x] = dp[x] + 1;
            rec2(next_x, a, dp);
        }
    }
}

ll solve2(ll a, ll n) {
    vector<ll> dp(MX, INF);
    dp[1] = 0;
    rec2(1, a, dp);
    /*
    vector<int> dbg = {1, 2, 4, 8, 16, 32, 64, 46, 92, 29, 58, 116, 611};
    for(auto e : dbg) {
        cout << e << " -> " << dp[e] << endl;
    }
    */
    if(dp[n] == INF)
        return -1;
    else
        return dp[n];
}

#ifdef ONLINE_JUDGE
int main() {
    ll a, n;
    cin >> a >> n;
    cout << solve2(a, n) << endl;
    return 0;
}
#endif