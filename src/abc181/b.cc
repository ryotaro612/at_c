#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll solve(ll n, vector<ll> a, vector<ll> b) {
    ll res = 0;
    for(ll i = 0; i < n; i++) {
        ll temp;
        if((b[i] - a[i] + 1) % 2 == 0) {
            temp = (a[i] + b[i]) * ((b[i] - a[i] + 1) / 2LL);
        } else {
            temp = ((a[i] + b[i]) / 2LL) * (b[i] - a[i] + 1);
        }
        //cout << i << " -> " << temp << endl;
        res += temp;
    }
    return res;
}
/*
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << solve(n, a, b);
}
*/