#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, vector<ll> x) {
    ll res = 100000000000000ll;

    for(ll i = 0; i <= 100; i++) {
        ll temp = 0ll;
        for(int j = 0; j < n; j++)
            temp += (i - x[j]) * (i - x[j]);

        res = min(res, temp);
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for(int i = 0; i < n; i++)
        cin >> x[i];
    cout << solve(n, x) << endl;
    return 0;
}
#endif