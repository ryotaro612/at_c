#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

double solve(ll n, ll m, ll d) {
    if(d == 0) {
        return ((ld)(m - 1ll) * (ld)n) / ((ld)n * (ld)n);
    }

    return ((ld)(m - 1ll) * (ld)2 * ((ld)n - (ld)d)) / ((ld)n * (ld)n);
}

#ifdef ONLINE_JUDGE
int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    cout << fixed << setprecision(12) << solve(n, m, d) << endl;
    return 0;
}
#endif