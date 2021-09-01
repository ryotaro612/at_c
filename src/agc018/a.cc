#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

#ifndef _debug
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 1ll) {
        if(k == a[0])
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ll g = gcd(max(a[0], a[1]), min(a[0], a[1]));
    for(int i = 2; i < n; i++)
        g = gcd(max(g, a[i]), min(g, a[i]));

    for(int i = 0; i < n; i++) {
        if(a[i] >= k && (a[i] - k) % g == 0ll) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
#endif