#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll powmod(ll n, ll mod) {
    ll res = 1ll, acc = 10ll;
    while(n) {
        if(n & 1ll) {
            res *= acc;
            res %= mod;
        }
        acc *= acc;
        acc %= mod;
        n >>= 1;
    }
    return res;
}

ll solve(ll n, ll m) { return (powmod(n, m * m) / m) % m; }

#ifdef ONLINE_JUDGE
int main() {
    ll n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
}
#endif