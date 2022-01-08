#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x) { return x * x + 2ll * x + 3ll; }

ll solve(ll t) { return f(f(f(t) + t) + f(f(t))); }

#ifdef ONLINE_JUDGE
int main() {
    ll t;
    cin >> t;
    cout << solve(t) << endl;
    return 0;
}
#endif