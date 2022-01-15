#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<int> solve(int n, int q, vector<ll> &av, vector<ll> &xv,
                  vector<ll> &kv) {
    unordered_map<ll, vector<int>> mp;
    rep(i, n) { mp[av[i]].push_back(i); }
    vector<int> res(q);
    rep(i, q) {
        ll x = xv[i];
        ll k = kv[i];
        if(mp.find(x) == mp.end()) {
            res[i] = -1;
        } else {
            if((int)mp[x].size() < k) {
                res[i] = -1;
            } else {
                res[i] = mp[x][k - 1] + 1;
            }
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> x(q), k(q);
    rep(i, q) { cin >> x[i] >> k[i]; }

    vector<int> res = solve(n, q, a, x, k);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif
