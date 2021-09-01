#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    ll n, a, x, y;
    cin >> n >> a >> x >> y;

    if(n < a) {
        cout << x * n << endl;
        return 0;
    }
    cout << x * a + y * (n - a) << endl;
    return 0;
}
#endif