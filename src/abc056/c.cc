#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll x) {
    for(ll i = 0ll;; i++) {
        if(x * 2 <= i * (i + 1))
            return i;
    }
    return -1;
}

#ifndef _LOCAL
int main() {
    ll x;
    cin >> x;
    cout << solve(x) << endl;

    return 0;
}
#endif