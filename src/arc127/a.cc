#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

/**
 * num = 1 -> 1
 * num = 2 -> 11
 */
ll generate_boundary(int num) {
    ll res = 0ll;
    for(int i = 0; i < num; i++) {
        res *= 10ll;
        res += 1ll;
    }
    return res;
}

ll solve(ll n) {
    ll ans = 0ll;
    for(int i = 1; i < 16; i++) {
        ll lower = generate_boundary(i);
        ll upper = lower + 1ll;
        while(n >= lower) {
            if(n >= upper) {
                ans += (upper - lower);
            } else { // n < upper
                ans += n - lower + 1ll;
            }
            lower *= 10ll;
            upper *= 10ll;
        }
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
