#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll sum = 0ll;
    for(int i = 0; x > 0ll; i++, x = x >> 1) {
        if(x & 1ll) {
            sum += a[i];
        }
    }
    cout << sum << endl;
    return 0;
}
#endif