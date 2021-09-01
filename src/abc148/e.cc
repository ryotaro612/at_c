#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n) {
    if(n % 2ll != 0ll)
        return 0ll;
    ll x = 5ll;
    ll res = 0ll;
    while(n > x) {
        res += n / (x * 2ll);
        x *= 5ll;
    }
    return res;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
#endif