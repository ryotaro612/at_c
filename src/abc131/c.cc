#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { 
    if(b == 0)
        return a;
    return gcd(b, a % b); 
}

ll calc_lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll temp(ll a, ll c, ll d) {
    ll lcm = calc_lcm(c, d);
    return a - a / c - a / d + a / lcm;
}

ll solve(ll a, ll b, ll c, ll d) { return temp(b, c, d) - temp(a - 1, c, d); }

#ifndef _LOCAL
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d) << endl;
}
#endif