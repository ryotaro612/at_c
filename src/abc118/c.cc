#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    ll res = gcd(max(a[0], a[1]), min(a[0], a[1]));
    for(int i = 2; i < n; i++) {
        res = gcd(max(res, a[i]), min(res, a[i]));
    }
    cout << res << endl;
    return 0;
}
#endif