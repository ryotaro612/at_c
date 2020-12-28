#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

int nth_bit(ll n, ll i) { return (n >> i) & 1; }

ll solve(ll n) {
    ll dp[61][3] = {0};
    dp[60][0] = 1LL;
    for(int d = 59; d >= 0; d--) {
        for(int s = 0; s <= 2; s++) {
            for(int k = 0; k <= 2; k++) {
                int s2 = min(2, 2 * s + nth_bit(n, d) - k);
                if(s2 >= 0) {
                    dp[d][s2] = (dp[d][s2] + dp[d + 1][s]) % MOD;
                }
            }
        }
    }
    return (((dp[0][0] + dp[0][1]) % MOD) + dp[0][2]) % MOD;
}
/*
int main() {
    ll n;
    cin >> n;
    cout << solve(n);
}
*/