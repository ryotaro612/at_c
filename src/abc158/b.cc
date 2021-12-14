#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(ll n, ll a, ll b) {
    ll div = n / (a + b);
    if(n % (a + b) == 0ll)
        return div * a;
    ll res = div * a;
    ll remain = n - div * (a + b);
    remain = min(a, remain);
    return res + remain;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    cout << solve(n, a, b) << endl;
    return 0;
}
#endif