#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    ll x, y, z, res = 0ll;
    cin >> x >> y >> z;

    while(z * y > x * (res + 1)) {
        res++;
    }

    cout << res << endl;
    return 0;
}
#endif