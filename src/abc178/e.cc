#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, vector<ll> x, vector<ll> y) {
    ll pmax = -1000000000000ll, pmin = 10000000000000ll, mmax = -1000000000000ll, mmin = 10000000000000ll;
    for(int i = 0; i < n; i++) {
        pmax = max(x[i] + y[i], pmax);
        pmin = min(x[i] + y[i], pmin);
        mmax = max(x[i] - y[i], mmax);
        mmin = min(x[i] - y[i], mmin);
    }
    ll res = max(pmax - pmin, mmax - mmin);
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    cout << solve(n, x, y) << endl;
}
#endif