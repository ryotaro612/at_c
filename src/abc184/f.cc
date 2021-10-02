#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<ll> enumerate_patterns(vector<ll> items) {
    int n = items.size();
    vector<ll> res;
    rep(i, 1 << n) {
        ll e = 0ll;
        rep(j, n) {
            if(i & (1 << j)) {
                e += items[j];
            }
        }
        res.push_back(e);
    }
    sort(res.begin(), res.end());
    return res;
}

ll solve(int n, ll t, vector<ll> &a) {
    if(n == 1)
        return a[0] > t ? 0ll : a[0];

    vector<ll> patterns =
        enumerate_patterns(vector<ll>(a.begin(), a.begin() + n / 2));

    vector<ll> rest(a.begin() + n / 2, a.end());
    ll res = 0ll;
    rep(i, 1 << rest.size()) {
        ll sum = 0ll;
        rep(j, rest.size()) {
            if(i & 1 << j) {
                sum += rest[j];
            }
        }
        int lb = -1, ub = patterns.size();
        while(ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if(patterns[mid] + sum > t)
                ub = mid;
            else
                lb = mid;
        }
        if(0<= lb && lb < (int) patterns.size()) {
            res = max(patterns[lb] + sum, res);
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    ll t;
    vector<ll> a(n);
    cin >> t;
    rep(i, n) cin >> a[i];
    cout << solve(n, t, a) << endl;
    return 0;
}
#endif