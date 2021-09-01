#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 1000000000000000ll;
    for(int i = 0; i < n; i++) {
        auto c = lower_bound(b.begin(), b.end(), a[i]);
        if(c == b.end()) {
            ans = min(abs(b[m - 1] - a[i]), ans);
        } else {
            ans = min(abs((*c) - a[i]), ans);
            if(c != b.begin()) {
                // auto f = *(c - 1);
                c--;
                ans = min(abs((*c) - a[i]), ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
#endif