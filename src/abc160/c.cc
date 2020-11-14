#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll k, ll n, vector<ll> a) {
    ll res = k;
    for(ll i = 0; i < n; i++) {
        ll temp;
        if(i == 0) {
            temp = min(a[n - 1] - a[i], k - (a[i + 1] - a[i]));
        } else if(i == n - 1) {
            temp = min(k - (a[i] - a[i - 1]), k - (k - a[i] + a[0]));
        } else {
            temp = min(k - (a[i + 1] - a[i]), k - (a[i] - a[i - 1]));
        }
        res = min(res, temp);
    }
    return res;
}
/*
int main() {
    ll k, n;
    cin >> k >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(k, n, a);
}
*/