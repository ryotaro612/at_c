#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll h, ll a, ll b, ll c, ll d, ll e) {
    ll threashold = h - n * e;
    if(threashold >= 0)
        return 0;
    ll res = numeric_limits<ll>::max();
    for(int i = 0; i <= n; i++) {
        ll num_a = i;
        ll t = threashold + (num_a * (e + b));
        if(t > 0) {
            res = min(res, num_a * a);
            continue;
        }
        ll num_c = (abs(t) / (d + e)) + 1;
        if(num_c > (n - num_a)) {
            continue;
        }
        res = min(res, num_a * a + num_c * c);

    }
    return res;
}
/*
int main() {
    ll n, h, a, b, c, d, e;
    cin >> n >> h >> a >> b >> c >> d >> e;

    cout << solve(n, h, a, b, c, d, e) << endl;
}
*/