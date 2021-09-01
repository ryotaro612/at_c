#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ld> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    ld avg = 0;
    for(auto aa : a)
        avg += aa;
    avg /= (ld)n;

    vector<ld> sum(n + 1, 0);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i - 1];

    ld ans = 10000000000;
    for(int i = 0; i < n; i++) {
        ld x = a[i] / (ld)2;

        ld expected = x + avg - (a[i] * (n - i) + sum[i]) / (ld)n;

        // cout << i << " -> " << x << " expected " << expected << endl;
        ans = min(expected, ans);
    }
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}
#endif