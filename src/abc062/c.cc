#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll h, ll w) {
    ll res = numeric_limits<ll>::max();
    if(h > 2) {
        if(h % 3 == 0)
            return 0;
        res = min(w, res);
    }
    if(w > 2) {
        if(w % 3 == 0)
            return 0;
        res = min(h, res);
    }
    for(ll i = 1; i < w; i++) {
        ll a = i * h, ww = w - i;
        if(h % 2 == 0) {
            res = min(abs(a - ww * (h / 2)), res);
        } else {
            ll b = h / 2 * ww, c = (h / 2 + 1) * ww;
            res = min(max(abs(a - b), max(abs(a - c), abs(b - c))), res);
        }
    }
    for(ll i = 1; i < h; i++) {
        ll a = i * w, hh = h - i;
        if(w % 2 == 0) {
            res = min(abs(a - hh * (w / 2)), res);
        } else {
            ll b = hh * (w / 2), c = hh * (w / 2 + 1);
            res = min(max(abs(a - b), max(abs(a - c), abs(b - c))), res);
        }
    }
    return res;
}
/*
int main() {
    ll h, w;
    cin >> h >> w;
    cout << solve(h, w) << endl;
}
*/