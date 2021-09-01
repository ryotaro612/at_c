#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    ll aa = max(a, b);
    ll bb = min(a, b);
    return (aa * bb) / gcd(aa, bb);
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    /*
    ll c = lcm(a[0], a[1]);
    for(int i = 2; i < n; i++) {
        c = lcm(c, a[i]);
    }
    cout << (c - 1) * n << endl;
    */
    ll res = 0ll;
    for(int i = 0; i < n; i++) {
        res += a[i] - 1;
    }
    cout << res << endl;

    return 0;
}
#endif