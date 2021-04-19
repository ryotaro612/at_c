#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> solve(int n, vector<ll> &d) {
    if(n == 1) {
        return make_pair(d[0], d[0]);
    }
    if(n == 2) {
        return make_pair(d[0] + d[1], abs(d[0] - d[1]));
    }

    vector<ll> sum(n + 1, 0ll);
    for(int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + d[i];

    ll res = numeric_limits<ll>::max();
    for(int i = 1; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            vector<ll> a = {sum[i], sum[j] - sum[i], sum[n] - sum[j]};
            if(a[0] + a[1] > a[2] && a[1] + a[2] > a[0] && a[0] + a[2] > a[1]) {
                return make_pair(sum[n], 0ll);
            }
            sort(a.begin(), a.end());
            res = min(res, a[2] - a[1] - a[0]);
        }
    }
    return make_pair(sum[n], res);
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> d(n);
    for(int i = 0; i < n; i++)
        cin >> d[i];

    auto res = solve(n, d);
    cout << res.first << endl;
    cout << res.second << endl;

    return 0;
}
#endif