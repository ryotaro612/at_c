#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const ll MOD = 998244353ll;

ll sub(ll a, ll b) {
    ll temp = (a - b) % MOD;
    if(temp < 0ll)
        return temp + MOD;
    else
        return temp;
}

ll solve(ll h, ll w, ll k, ll x1, ll y1, ll x2, ll y2) {
    ll outside = 0ll, x = 0ll, y = 0ll, xy = 0ll;
    if(x1 == x2) {
        if(y1 == y2)
            xy = 1ll;
        else
            y = 1ll;
    } else {
        if(y1 == y2)
            x = 1ll;
        else
            outside = 1ll;
    }
    rep(i, k) {
        // cout << "outside: " << outside << " x: " << x << " y: " << y
        //      << " xy: " << xy << endl;

        // ll next_outside = (outside * sub(h, 2ll) % MOD);
        // next_outside += (outside * sub(w, 2ll) % MOD);
        ll next_outside = ((sub(h, 2ll) + sub(w, 2ll)) % MOD) * outside % MOD;
        next_outside %= MOD;
        next_outside += (sub(w, 1ll) * x % MOD);
        next_outside %= MOD;
        next_outside += (sub(h, 1ll) * y % MOD);
        next_outside %= MOD;

        ll next_x = outside;
        next_x += (sub(h, 2ll) * x % MOD);
        next_x %= MOD;
        next_x += (xy * sub(h, 1ll) % MOD);
        next_x %= MOD;

        ll next_y = outside;
        next_y += (sub(w, 2ll) * y % MOD);
        next_y %= MOD;
        next_y += (xy * sub(w, 1ll) % MOD);
        next_y %= MOD;

        xy = (x + y) % MOD;
        outside = next_outside;
        x = next_x;
        y = next_y;
    }
    return xy;
}

#ifdef ONLINE_JUDGE
int main() {
    ll h, w, k, x1, y1, x2, y2;
    cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
    cout << solve(h, w, k, x1, y1, x2, y2) << endl;
    return 0;
}
#endif
