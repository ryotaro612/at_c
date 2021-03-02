#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

set<ll> calc_divisors(ll n) {
    set<ll> res;
    for(ll i = 1ll; i * i <= n; i++) {
        if(n % i == 0ll) {
            res.insert(i);
            if(i * i != n)
                res.insert(n / i);
        }
    }
    return res;
}

ll solve(int n, vector<ll> a) {
    vector<set<ll>> gcd_l(n), gcd_r(n);
    gcd_l[0] = calc_divisors(a[0]);
    gcd_r[0] = calc_divisors(a[n - 1]);
    for(int i = 1; i < n; i++) {
        set<ll> divisors = calc_divisors(a[i]);
        set<ll> prev = gcd_l[i - 1];
        for(auto d : divisors) {
            if(prev.find(d) != prev.end())
                gcd_l[i].insert(d);
        }

        set<ll> divisors_r = calc_divisors(a[n - 1 - i]);
        set<ll> prev_r = gcd_r[i - 1];
        for(auto d : divisors_r) {
            if(prev_r.find(d) != prev_r.end())
                gcd_r[i].insert(d);
        }
    }
    ll res = 1;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            res = max(*(gcd_r[n - 2].rbegin()), res);
        } else if(i == n - 1) {
            res = max(*(gcd_l[n - 2].rbegin()), res);
        }
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
    return 0;
}
#endif