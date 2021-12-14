#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    ll a, b, k;
    cin >> a >> b >> k;

    if(a >= k)
        cout << a - k << " " << b << endl;
    else {
        // a< k
        k -= a;
        cout << 0 << " " << max(b - k, 0ll) << endl;
    }

    return 0;
}
#endif