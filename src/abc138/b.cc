#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    vector<ld> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ld ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (ld)1 / a[i];
    }
    cout << fixed << setprecision(12) << (ld)1 / ans << endl;
    return 0;
}
#endif