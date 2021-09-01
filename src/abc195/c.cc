#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n) {
    ll ans = 0ll;
    if(n < 1000ll)
        return ans;
    ans += (n - 1000ll + 1ll);
    if(n < 1000000ll) // 10^6  ',' x 2;
        return ans;
    ans += (n - 1000000ll + 1ll);
    if(n < 1000000000ll) // 10 ^9 ',' x 3;
        return ans;
    ans += (n - 1000000000ll + 1ll);
    if(n < 1000000000000ll) // 10 ^ 12 ',' * 4;
        return ans;
    ans += (n - 1000000000000ll + 1ll);
    if(n < 1000000000000000ll) // 10 ^ 15 ',' * 5;
        return ans;
    ans += (n - 1000000000000000ll + 1ll);
    return ans;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif