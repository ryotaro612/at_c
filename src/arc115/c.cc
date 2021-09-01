#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> calc_divisors(int n) {
    vector<ll> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<ll> solve(ll n) {
    vector<ll> res(n);
    res[0] = 1;
    for(int i = 1; i < n; i++) {
        ll r = 1;
        auto divisors = calc_divisors(i + 1);
        for(auto d : divisors) {
            if(r == res[d - 1])
                r++;
        }
        res[i] = r;
    }
    return res;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    auto res = solve(n);
    for(int i = 0; i < n; i++) {
        cout << res[i];
        if(i == n - 1)
            cout << endl;
        else
            cout << " ";
    }
}
#endif