#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const ll MOD = 1000000007ll;

void rec(int index, ll k, vector<vector<int>> &g, ll &ans, vector<int> &depth,
         int brother_index) {
    if(depth[index] == 0) {
        ans *= k;
    } else if(depth[index] == 1) {
        ans *= max(0ll, (k - 1ll - brother_index));
    } else {
        ans *= max(0ll, (k - 2ll - brother_index));
    }
    ans %= MOD;
    for(int i = 0, brother_index = 0; i < (int)g[index].size(); i++) {
        int child = g[index][i];
        if(depth[child] >= 0)
            continue;
        depth[child] = depth[index] + 1;
        rec(child, k, g, ans, depth, brother_index);
        brother_index++;
    }
}

ll solve(int n, int k, vector<int> &a, vector<int> &b) {
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        g[--a[i]].push_back(--b[i]);
        g[b[i]].push_back(a[i]);
    }
    vector<int> depth(n, -1);
    ll ans = 1ll;
    depth[0] = 0;
    rec(0, k, g, ans, depth, 0);
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n - 1), b(n - 1);
    rep(i, n - 1) cin >> a[i] >> b[i];
    cout << solve(n, k, a, b) << endl;
    return 0;
}
#endif