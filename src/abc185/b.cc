#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(ll n, ll m, ll t, vector<ll> a, vector<ll> b) {
    ll charge = n;
    for(int i = 0; i < m; i++) {
        charge -= a[i] - (i == 0 ? 0ll : b[i - 1]);
        if(charge <= 0)
            return "No";
        charge += b[i] - a[i];
        charge = min(charge, n);
    }
    charge -= t - b[m - 1];
    if(charge <= 0ll)
        return "No";
    return "Yes";
}

#ifndef _debug
int main() {
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(m), b(m);
    for(int i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    cout << solve(n, m, t, a, b) << endl;
}
#endif