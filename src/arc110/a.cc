#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll solve(ll n) {
    ll res = 1ll;
    for(int i = 2; i <= n; i++) {
        res = lcm(res, i);
    }
    return res + 1ll;
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
#endif