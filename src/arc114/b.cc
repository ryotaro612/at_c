#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const ll MOD = 998244353ll;
static const ll MAX = 200001;

ll par[MAX];

ll calc_patterns(ll count) {
    ll temp = 1ll;
    for(ll i = 0ll; i < count; i++) {
        temp *= 2;
        temp %= MOD;
    }
    return (temp - 1ll) % MOD;
}

void init(ll n) {
    for(ll i = 0ll; i < n; i++) {
        par[i] = i;
    }
}

ll find(ll x) {
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void unite(ll x, ll y) {
    x = find(x), y = find(y);
    if(x == y)
        return;
    par[x] = y;
}

bool is_same(ll x, ll y) { return find(x) == find(y); }

ll solve(ll n, vector<ll> f) {
    init(n);
    for(ll i = 0ll; i < n; i++)
        unite(i, f[i] - 1);
    set<ll> loop_set;
    for(ll i = 0ll; i < n; i++)
        loop_set.insert(find(i));

    return calc_patterns((ll)loop_set.size());
}

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    vector<ll> f(n);
    for(int i = 0; i < n; i++)
        cin >> f[i];
    cout << solve(n, f) << endl;
}
#endif