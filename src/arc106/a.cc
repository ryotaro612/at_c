#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef int64_t ll;
using namespace std;

pair<ll, ll> solve(ll n) {
    for(ll i = 3, a = 1; i < n; i *= 3, a++) {
        for(ll j = 5, b = 1; j < n; j *= 5, b++) {
            if(i + j == n) {
                return make_pair(a, b);
            }
        }
    }
    return make_pair(-1, -1);
}

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    pair<ll, ll> res = solve(n);
    if(res.first == -1ll)
        cout << -1 << endl;
    else
        cout << res.first << " " << res.second << endl;
    return 0;
}
#endif