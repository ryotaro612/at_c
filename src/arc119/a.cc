#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll pow(ll x, ll n) {
    ll res = 1ll;
    while(n > 0) {
        if(n & 1) {
            res *= x;
        }
        n >>= 1;
        x *= x;
    }
    return res;
}

ll solve(ll n) {

    ll b = 0ll;
    while(true) {
        if(pow(2, b + 1) > n)
            break;
        b++;
    }
    ll ans = numeric_limits<ll>::max();
    for(ll i = 0; i <= b; i++) {
        ll a = n / pow(2ll, i);
        ll c = n - pow(2ll, i) * a;
        //cout << a << " " << i << " " << c << endl;
        ans = min(ans, a + i + c);
    }
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif