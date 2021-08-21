#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool is_ok(string &s, string &t) {
    set<char> ss;
    for(auto c : s)
        ss.insert(c);

    for(auto c : t)
        if(ss.find(c) == ss.end())
            return false;
    return true;
}

void build(string &s, vector<vector<int>> &dp) {
    string a = s + s;
    int n = a.size();
    dp = vector<vector<int>>(n + 1, vector<int>(26, -1));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < 26; j++) {
            if(dp[i + 1][j] == -1)
                dp[i][j] = -1;
            else
                dp[i][j] = dp[i + 1][j] + 1;
        }
        dp[i][a[i] - 'a'] = 1;
    }
}

ll solve(string s, string t) {
    if(!is_ok(s, t))
        return -1;

    vector<vector<int>> dp;
    build(s, dp);
    ll ans = 0ll;

    for(int i = 0, j = 0; i < t.size(); i++) {
        int c = t[i] - 'a';
        ans += dp[j][c];
        j += dp[j][c];
        j %= (int)s.size();
    }
    return ans;
}

#ifndef _LOCAL
int main() {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
    return 0;
}
#endif