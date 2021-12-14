#define _GLIBXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, ll x, vector<ll> a) {
    ll res_l = 0ll;
    vector<ll> b(a), c(a);
    for(int i = 0; i < n - 1; i++) {
        if(b[i] + b[i + 1] > x) {
            ll diff = (b[i] + b[i + 1] - x);
            res_l += diff;
            if(b[i + 1] >= diff) {
                b[i + 1] -= diff;
            } else {
                b[i] -= (diff - b[i + 1]);
                b[i + 1] = 0;
            }
        }
    }
    ll res_r = 0ll;
    for(int i = n - 2; i >= 0; i--) {
        if(c[i] + c[i + 1] > x) {
            ll diff = (c[i] + c[i + 1] - x);
            res_r += diff;
            if(c[i] >= diff) {
                c[i] -= diff;
            } else {
                c[i + 1] -= (diff - c[i]);
                c[i] = 0;
            }
        }
    }
    return min(res_l, res_r);
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, x, a) << endl;
}
#endif