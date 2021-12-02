#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, string s) {
    vector<pair<char, ll>> chars;
    for(int i = 0; i < n; i++) {
        if(chars.size() == 0 || chars.back().first != s[i])
            chars.push_back({s[i], 1});
        else {
            chars.back().second++;
        }
    }
    ll res = 0ll;
    for(auto p : chars) {
        res += p.second * (p.second - 1l) / 2ll;
    }
    return res;
}
#ifndef _debug
int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
    return 0;
}
#endif