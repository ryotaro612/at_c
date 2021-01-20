#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> solve(ll a, ll b, ll c, ll d, ll e, ll f) {
    pair<ll, ll> res = make_pair(0, 0);
    for(ll aa = 0; aa <= 30; aa++) {
        for(ll bb = 0; bb <= 30; bb++) {
            ll water = 100 * a * aa + 100 * b * bb;
            if(water == 0 || water > f) {
                continue;
            }
            ll max_salt = (aa * a + b * bb) * e;
            for(ll cc = 0; cc * c <= max_salt; cc++) {
                for(ll dd = 0; dd * d <= max_salt; dd++) {
                    ll salt = c * cc + d * dd;
                    if(salt > max_salt || water + salt > f) {
                        continue;
                    }
                    if(res.first == 0 && res.second == 0) {
                        res = make_pair(water + salt, salt);
                        continue;
                    }
                    if(res.second * (water + salt) < salt * res.first) {
                        res = make_pair(water + salt, salt);
                    }
                }
            }
        }
    }
    return res;
}
/*
int main() {
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    pair<ll, ll> res = solve(a, b, c, d, e, f);
    cout << res.first << " " << res.second << endl;
}
*/