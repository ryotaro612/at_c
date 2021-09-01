#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

pair<ld, ld> solve(ll n, ll a, ll b, vector<ll> s) {
    ll mini = 10000000000ll, maxi = -1ll;
    ll sum = 0ll;
    for(int i = 0; i < n; i++) {
        sum += s[i];
        mini = min(mini, s[i]);
        maxi = max(maxi, s[i]);
    }
    if(maxi == mini)
        return make_pair(-1, -1);
    ld p = (ld)b / (ld)(maxi - mini);
    ld q = ((ld)a * (ld)n - p * (ld)sum) / (ld)n;
    return make_pair(p, q);
}

#ifndef _debug
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    pair<ld, ld> res = solve(n, a, b, s);
    if(res.first == -1 && res.second == -1)
        cout << -1;
    else {
        cout << fixed << setprecision(12) << res.first << " ";
        cout << fixed << setprecision(12) << res.second;
    }
    cout << endl;
    return 0;
}
#endif