#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    for(int i = 0; i < n + 1; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    ll ans = 0ll;
    for(int i = 0; i < n; i++) {
        ll taosu = min(a[i], b[i]);
        ans += taosu;
        a[i] -= taosu;
        ll next_taosu = min(a[i + 1], b[i] - taosu);
        a[i + 1] -= next_taosu;
        ans += next_taosu;
    }
    cout << ans << endl;
    return 0;
}
#endif