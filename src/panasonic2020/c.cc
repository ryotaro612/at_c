#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _LOCAL
int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    if(c - a - b <= 0) {
        cout << "No" << endl;
        return 0;
    }

    if(4 * a * b < (c - a - b) * (c - a - b)) {
        cout << "Yes" << endl;
        return 0;
    } else {
        cout << "No" << endl;
        return 0;
    }

    return 0;
}
#endif