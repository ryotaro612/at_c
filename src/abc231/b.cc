#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(int n, vector<string> s) {
    unordered_map<string, int> mp;
    for(auto p : s) {
        mp[p]++;
    }
    vector<pair<int, string>> order;
    for(auto p : mp) {
        order.push_back({p.second, p.first});
    }
    sort(order.begin(), order.end());
    return order.back().second;
}
#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    cout << solve(n, s) << endl;

    return 0;
}
#endif
