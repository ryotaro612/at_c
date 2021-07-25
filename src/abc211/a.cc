#include <bits/stdc++.h>
typedef long double ld;
using namespace std;

#ifndef _LOCAL
int main() {
    ld a, b;
    cin >> a >> b;
    ld ans = (a - b) / (ld)3 + b;

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
#endif