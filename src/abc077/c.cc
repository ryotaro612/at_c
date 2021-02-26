#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int search(ll v, vector<ll> a) {
    int lb = -1, ub = (int)a.size();

    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(v < a[mid])
            ub = mid;
        else // v >= a[mid]
            lb = mid;
    }
    return ub;
}
// vより真に小さいa[i]のi
int l_search(ll v, vector<ll> a) {
    int lb = -1, ub = (int)a.size();
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(v <= a[mid])
            ub = mid;
        else // v > a[mid]
            lb = mid;
    }
    return lb;
}

ll solve(int n, vector<ll> a, vector<ll> b, vector<ll> c) {
    sort(a.begin(), a.end());
    //sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll res = 0ll;

    for(int i = 0; i < n; i++) {
        auto a_iter = lower_bound(a.begin(), a.end(), b[i]);
        if(a_iter == a.begin())
            continue;
        auto c_iter = upper_bound(c.begin(), c.end(), b[i]);
        if(c_iter == c.end())
            continue;
        res += ((a_iter - a.begin())) * (c.end() - c_iter);
    }

    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    cout << solve(n, a, b, c) << endl;
    return 0;
}
#endif