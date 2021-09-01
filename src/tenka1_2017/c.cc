#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Res {
    ll h, n, w;
};

Res solve(ll N) {
    ll mx = 3500ll;
    for(ll h = 1ll; h <= mx; h++) {
        for(ll n = 1ll; n <= mx; n++) {
            //cout << "begin"  << endl;
            ll numerator = n * h * N;
            ll denominator = 4ll * h * n - N * n - h * N;
            //cout << "from"  << endl;
            if(denominator == 0ll || numerator % denominator != 0ll)
                continue;
            ll w = numerator / denominator;
            if(w > 0ll) {
                return {h, n, w};
            }
        }
    }
    return {0, 0, 0};
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    Res res = solve(n);
    cout << res.h << " " << res.n << " " << res.w << endl;
    return 0;
}
#endif