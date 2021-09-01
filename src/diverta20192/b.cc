#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<ll> x, vector<ll> y) {
    map<pair<ll, ll>, int> mp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            mp[make_pair(x[j] - x[i], y[j] - y[i])]++;
            mp[make_pair(x[i] - x[j], y[i] - y[j])]++;
        }
    }
    int ans = 0;
    for(auto p : mp) {
        //cout << p.second << endl;
        ans = max(ans, p.second);
    }
    return n - ans;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    cout << solve(n, x, y) << endl;
    return 0;
}
#endif