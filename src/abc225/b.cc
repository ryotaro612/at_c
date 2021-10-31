#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(int n, vector<int> &a, vector<int> &b) {
    unordered_map<int, int> mp;
    rep(i, n - 1) {
        mp[a[i]]++;
        mp[b[i]]++;
    }
    for(auto e : mp) {
        if(e.second == n - 1)
            return "Yes";
    }
    return "No";
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1), b(n - 1);
    rep(i, n - 1) cin >> a[i] >> b[i];
    cout << solve(n, a, b) << endl;
    return 0;
}
#endif
