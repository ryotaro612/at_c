#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, vector<ll> a, vector<ll> b) {
    ll res = 10000000ll;
    for(int i = 0; i < n; i++) {
        res = min(res, a[i] + b[i]);
    }
    vector<pair<ll, int>> av(n), bv(n);
    for(int i = 0; i < n; i++) {
        av[i] = make_pair(a[i], i);
        bv[i] = make_pair(b[i], i);
    }
    sort(av.begin(), av.end());
    sort(bv.begin(), bv.end());

    int bv_index = 0;
    while(true) {
        if(av[0].second == bv[bv_index].second) {
            bv_index++;
        } else {
            res = min(res, max(av[0].first, bv[bv_index].first));
            break;
        }
    }
    int av_index = 0;
    while(true) {
        if(av[av_index].second == bv[0].second) {
            av_index++;
        } else {
            res = min(res, max(av[av_index].first, bv[0].first));
            break;
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << solve(n, a, b) << endl;
    return 0;
}
#endif