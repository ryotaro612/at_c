#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const ll MOD = 1000000007ll;

ll pow_kai(ll a, ll n) { // aのn乗を計算します。
    ll x = 1ll;
    while(n > 0ll) { //全てのbitが捨てられるまで。
        if(n & 1) {  // 1番右のbitが1のとき。
            x = x * a;
            x %= MOD;
        }
        a = a * a;
        a %= MOD;
        n >>= 1; // bit全体を右に1つシフトして一番右を捨てる。
    }
    return x;
}

ll solve(ll n, ll p) {
    if(n == 1ll)
        return p - 1ll;

    return ((p - 1ll) * pow_kai(p - 2ll, n - 1ll)) % MOD;
}

#ifndef _debug
int main() {
    ll n, p;
    cin >> n >> p;
    cout << solve(n, p) << endl;
    return 0;
}
#endif