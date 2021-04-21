#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0ll)
        return a;
    return gcd(b, a % b);
}

#ifndef _LOCAL
int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> xv(n);
    for(int i = 0; i < n; i++)
        cin >> xv[i];

    if(n == 1) {
        cout << abs(x - xv[0]) << endl;
        return 0;
    }

    vector<ll> dif(n);
    for(int i = 0; i < n; i++) {
        dif[i] = abs(xv[i] - x);
    }
    ll res = gcd(max(dif[0], dif[1]), min(dif[0], dif[1]));
    for(int i = 2; i < n; i++)
        res = gcd(max(res, dif[i]), min(res, dif[i]));
    cout << res << endl;

    return 0;
}
#endif