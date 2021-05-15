#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    ll a, b;
    cin >> a >> b;
    if(a == b) {
        cout << 0 << endl;
        return 0;
    } else if((a + b) % 2ll == 0ll) {
        cout << (a + b) / 2ll << endl;
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
#endif