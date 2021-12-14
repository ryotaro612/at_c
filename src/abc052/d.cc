#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, ll a, ll b, vector<ll> x) {
    ll res = 0ll;
    for(int i = 0; i < n - 1; i++) {
        ll walk = (x[i + 1] - x[i]) * a;
        res += walk > b ? b : walk;
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    vector<ll> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << solve(n, a, b, x);
}
#endif