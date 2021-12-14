#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll p, ans = 0ll;
    cin >> p;
    vector<ll> c = {1ll,   2ll,    6ll,     24ll,     120ll,
                    720ll, 5040ll, 40320ll, 362880ll, 3628800ll};
    for(int i = 9; i >= 0; i--) {
        ll num = p / c[i];
        num = min(100ll, num);
        p -= num * c[i];
        ans += num;
    }
    cout << ans << endl;
}

#ifdef ONLINE_JUDGE
int main() {
    solve();

    return 0;
}
#endif