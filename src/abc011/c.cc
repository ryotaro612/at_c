#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 400;

int dfs(int start, vector<int> &dp, set<int> &ng) {
    if(dp[start] >= 0) {
        return dp[start];
    }
    if(ng.find(start) != ng.end()) {
        return dp[start] = INF;
    }
    int one = INF, two = INF, three = INF;
    if(start - 1 >= 0) {
        one = dfs(start - 1, dp, ng);
    }
    if(start - 2 >= 0) {
        two = dfs(start - 2, dp, ng);
    }
    if(start - 3 >= 0) {
        three = dfs(start - 3, dp, ng);
    }
    return dp[start] = min(one, min(two, three)) + 1;
}

string solve(int n, vector<int> ng) {
    vector<int> dp(301, -1);
    dp[0] = 0;
    set<int> ng_set;
    ng_set.insert(ng[0]);
    ng_set.insert(ng[1]);
    ng_set.insert(ng[2]);
    int res = dfs(n, dp, ng_set);
    return res <= 100 ? "YES" : "NO";
}
/*
int main() {
    int n;
    vector<int> ng(3);
    cin >> n >> ng[0] >> ng[1] >> ng[2];
    cout << solve(n, ng) << endl;
}
*/