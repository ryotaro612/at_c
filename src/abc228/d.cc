#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

const ll N = 1048576ll;
ll build_cache(unordered_map<ll, ll> &skip, unordered_map<ll, ll> &nneg, ll h) {
    ll index = h % N;
    if(nneg.find(index) == nneg.end() || nneg[index] == -1ll) {
        skip[index] = index;
        return index;
    } else {
        if(skip[index] == index) {
            return skip[index] = build_cache(skip, nneg, h + 1ll);
        } else {
            return skip[index] = build_cache(skip, nneg, skip[index]);
        }
    }
}

vector<ll> solve(int q, vector<int> &t, vector<ll> &x) {
    unordered_map<ll, ll> skip, nneg;
    vector<ll> res;
    rep(i, q) {
        if(t[i] == 1) {
            ll dest = build_cache(skip, nneg, x[i]);
            nneg[dest] = x[i];
        } else {
            auto found = nneg.find(x[i] % N);
            if(found == nneg.end()) {
                res.push_back(-1);
            } else {
                res.push_back(found->second);
            }
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int q;
    cin >> q;
    vector<int> t(q);
    vector<ll> x(q);
    rep(i, q) cin >> t[i] >> x[i];
    vector<ll> res = solve(q, t, x);
    for(auto e : res)
        cout << e << endl;
    return 0;
}
#endif