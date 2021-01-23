#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, vector<ll> t, vector<ll> a) {
    ll tt = 1, aa = 1;
    for(ll i = 0; i < n; i++) {
        if(t[i] >= tt && a[i] >= aa) {
            tt = t[i];
            aa = a[i];
            continue;
        }
        if(a[i] * tt > t[i] * aa) {
            // ｔで計算する
            if(tt % t[i] == 0) {
                ll bai = (tt / t[i]);
                tt = t[i] * bai;
                aa = bai * a[i];
                continue;
            } else {
                ll bai = (tt / t[i]) + 1;
                tt = t[i] * bai;
                aa = bai * a[i];
            }
        } else {
            if(aa % a[i] == 0) {
                ll bai = (aa / a[i]);
                aa = a[i] * bai;
                tt = bai * t[i];
                continue;
            } else {
                ll bai = (aa / a[i]) + 1;
                aa = a[i] * bai;
                tt = bai * t[i];
            }
        }
    }

    return tt + aa;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> t(n), a(n);
    for(ll i = 0; i < n; i++) {
        cin >> t[i] >> a[i];
    }
    cout << solve(n, t, a) << endl;
}