#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    for(ll ans = 0ll;; ans++) {
        if((((ll)1ll << (ans + 1ll))) > n) {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}
#endif