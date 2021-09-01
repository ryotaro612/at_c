#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(ll n, ll k, vector<ll> a, vector<ll> b) {
    ll mx = 100001;
    vector<ll> c(mx, 0);
    for(ll i = 0ll; i < n; i++) {
        c[a[i]] += b[i];
    }
    ll acc = 0ll;
    for(ll i = 0ll; i < mx; i++) {
        if(acc + c[i] >= k) {
            return i;
        }
        acc += c[i];
    }
    return -1;
}

#ifndef _debug
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(ll i = 0ll; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << solve(n, k, a, b) << endl;
    return 0;
}
#endif