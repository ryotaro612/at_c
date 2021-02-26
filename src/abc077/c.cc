#define _GLIBCXX_DEBUG
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
#ifdef _LOCAL
/*
    cout << search(3, {1, 3, 4}) << endl;
    cout << search(3, {3, 3, 4}) << endl;
    cout << search(3, {4, 5, 6}) << endl;
    cout << l_search(3, {1, 3, 4}) << endl;
    cout << l_search(3, {3, 3, 4}) << endl;
    cout << l_search(3, {4, 5, 6}) << endl;
    */
#endif
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll res = 0ll;

    for(int i = 0; i < n; i++) {
        int c_i =  search(b[i], c);
        if(c_i == n)
            continue;
        int a_i = l_search(b[i], a);
        if(a_i == -1)
            continue;
#ifdef _LOCAL
        cout << b[i] << "-> " << a_i << " " << c_i << endl;
#endif
        res += (a_i + 1) * (n - c_i);
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