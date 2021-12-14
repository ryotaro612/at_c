#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n, vector<string> s) {
    for(int i = 0; i < n; i++)
        sort(s[i].begin(), s[i].end());
    map<string, int> mp;
    for(int i = 0; i < n; i++)
        mp[s[i]]++;
    ll res = 0ll;
    for(auto p : mp)
        res += ((ll)p.second * ((ll)p.second - 1ll)) / 2ll;
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    cout << solve(n, s) << endl;
}
#endif