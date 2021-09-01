#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll MOD = 1000000007ll;

ll solve(ll n) {
    if(n == 1) 
        return 1ll;
    vector<int> factors(n+1, 0);
    for(int i = 2; i <= n; i++) {
        int m = i;
        for(ll a = 2; a * a <= m; a++) {
            while(m % a == 0) {
                factors[a]++;
                m /= a;
            }
        }
        if(m != 1)
            factors[m]++;
    }
    ll res = 1;
    for(auto f : factors) {
        if(f == 0)
            continue;
        res *= (f + 1);
        res %= MOD;
    }
    return res;
}
#ifndef _debug
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif