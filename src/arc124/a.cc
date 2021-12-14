#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const ll MOD = 998244353ll;

ll solve(int n, int k, vector<char> &c, vector<int> &kv) {
    rep(i, k) kv[i]--;

    vector<int> l(n, -1), r(n, -1);
    rep(i, k) {
        if(c[i] == 'L') {
            l[kv[i]] = i;
        } else {
            r[kv[i]] = i;
        }
    }
    ll ans = 1ll;

    rep(i, n) {
        if(l[i] != -1 || r[i] != -1)
            continue;
        ll cand = k;
        for(int j = n - 1; i < j; j--) {
            if(l[j] != -1)
                cand--;
        }
        for(int j = 0; j < i; j++) {
            if(r[j] != -1)
                cand--;
        }
        ans *= cand;
        ans %= MOD;
    }
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    vector<char> c(k);
    vector<int> kv(k);

    rep(i, k) cin >> c[i] >> kv[i];

    cout << solve(n, k, c, kv) << endl;
    return 0;
}
#endif