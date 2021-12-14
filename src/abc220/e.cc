#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const ll MOD = 998244353ll;

ll pow(ll x, ll n) {
    ll res = 1ll;
    while(n > 0) {
        if(n & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

ll sub(ll a, ll b) {
    ll res = a - b;
    if(res < 0)
        res += MOD;
    return res;
}

ll solve(ll n, ll d) {
    // 木の高さh: 0 <= h < n
    // 高さhのノードから左か右下に距離l: 0<= l < n - h
    // 距離lのパターン数 l == 0, 1 => 1, else => pow(2, max(l-1, 0))
    // 下に距離lとれるノードは高さn-l-1まで
    // 高さn-l-1までのノードの総数は、pow(2, n-l-1+1) -1
    ll ans = 0ll;
    for(ll left = 0ll; left <= d; left++) {
        ll right = d - left;
        ll required_height = max(left, right);
        if(n - required_height - 1ll < 0)
            continue;
        ll node_num = sub(pow(2ll, n - required_height), 1ll);
        ll left_num = pow(2ll, max(left - 1ll, 0ll));
        ll right_num = pow(2ll, max(right - 1ll, 0ll));
        ll temp = node_num * left_num % MOD * right_num % MOD;
        ans = (ans + temp) % MOD;
    }
	ans *= 2ll;
	ans %= MOD;
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n, d;
    cin >> n >> d;
    cout << solve(n, d) << endl;
    return 0;
}
#endif