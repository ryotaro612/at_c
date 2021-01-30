#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    ll res = 0;
    for(int i = 1ll;; i++) {
        ll temp = 2ll * n - pow(i, 2ll) + i;
        ll div = 2ll * i;
        if(temp < 0) {
            break;
        }
        if(temp % div != 0) {
            continue;
        }
        ll a = temp / div;
        if(a > 0) {
            res += 2;
        } else {
            break;
        }
    }
    return res;
}
/*
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
*/