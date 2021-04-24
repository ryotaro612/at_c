#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll m) {
    if(n == 1 && m == 1) {
        return 1;
    }
    if(n == 1 || m == 1) {
        return max(n, m) - 2;
    }
    // n >= 2 && m >= 2
    return (n - 2ll) * (m - 2ll);
}

#ifndef _LOCAL
int main() {
    ll n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
}
#endif