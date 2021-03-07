#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ld solve(ll n) {
    ld res = 0;
    for(int i = 1; i < n; i++) {
        res += (ld)n / (ld)i;
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    cout << fixed << setprecision(12) << solve(n) << endl;
    return 0;
}
#endif