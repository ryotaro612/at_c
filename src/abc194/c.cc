#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n, vector<ll> a) {
    vector<ll> sum(n + 1, 0ll), sum2(n + 1, 0ll);
    for(int i = 1; i < n + 1; i++) {
        sum[i] = a[i - 1] + sum[i - 1];
        sum2[i] = a[i - 1] * a[i - 1] + sum2[i - 1];
    }
    /*
    for(auto s: sum2) {
        cout << s << " ";
    }
    cout << endl;
    */
    ll res = 0ll;
    for(int i = 2; i <= n; i++) {
        ll temp = (i - 1) * a[i - 1] * a[i - 1] - 2 * a[i - 1] * sum[i - 1] +
                  sum2[i - 1];
        // cout << i << " -> " << temp << endl;
        res += temp;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
    return 0;
}
#endif