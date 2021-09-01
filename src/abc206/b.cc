#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    ll n;
    cin >> n;

    for(ll i = 1;; i++) {
        ll sum = i * (i + 1ll) / 2ll;
        if(sum >= n) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
#endif