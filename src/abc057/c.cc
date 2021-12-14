#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int diff(ll a, ll b) {
    return max((int)to_string(a).size(), (int)to_string(b).size());
}

ll solve(ll n) {
    vector<pair<ll, ll>> p;
    for(ll i = 1ll; i * i <= n; i++) {
        if(n % i == 0) {
            p.push_back(make_pair(i, n / i));
        }
    }
    int res = 1000000;
    for(auto pp : p) {
        res = min(res, diff(pp.first, pp.second));
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif