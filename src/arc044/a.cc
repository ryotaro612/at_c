#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool is_prime(ll n) {
    vector<ll> ans;
    for(ll i = 2ll; i * i <= n; i++) {
        if(n % i == 0ll)
            return false;
    }
    return true;
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    if(n == 1ll) {
        cout << "Not Prime" << endl;
        return 0;
    }

    if(is_prime(n)) {
        cout << "Prime" << endl;
        return 0;
    }

    if(n % 2ll != 0ll && n % 5ll != 0ll && n % 3 != 0ll) {
        cout << "Prime" << endl;
        return 0;
    }

    cout << "Not Prime" << endl;

    return 0;
}
#endif