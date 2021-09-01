#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow2(ll n) {
    ll ans = 1ll;
    while(n-- != 0ll) {
        ans *= 2ll;
    }
    return ans;
}

#ifndef _debug
int main() {
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll all = pow2(n);
    ll even = 0ll, odd = 0ll;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2ll == 0ll)
            even++;
        else
            odd++;
    }
    if(odd == 0) {
        if(p == 1) {
            cout << 0 << endl;
        } else
            cout << all << endl;
        return 0;
    }
    ll even_pattern = pow2(even);
    ll odd_pattern = pow2(odd - 1ll);
    if(p == 1ll) {
        cout << even_pattern * odd_pattern << endl;
    } else
        cout << all - (even_pattern * odd_pattern) << endl;

    return 0;
}
#endif