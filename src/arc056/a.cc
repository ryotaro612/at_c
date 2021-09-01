#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    ll a, b, k, l;
    cin >> a >> b >> k >> l;

    if(b >= l * a) {
        cout << a * k << endl;
        return 0;
    }
    ll n_set_money = k / l * b;
    cout << "b money " << n_set_money << endl;
    ll ans = a * (k - (k / l * l)) + n_set_money;

    cout << min(ans, (k / l + 1) * b) << endl;
    return 0;
}
#endif