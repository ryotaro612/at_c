#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll acc(ll a, ll num) {
    // a - num +1 から aまでの数
    ll b = a + (a - num + 1ll);
    ll res = b * (num / 2ll);
    res += b / 2ll * (num % 2ll);
    return res;
}


#ifdef ONLINE_JUDGE
int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    ll lb = -1ll, ub = a[n - 1] + 1ll; // 2e9 + 1ll;
    while(ub - lb > 1ll) {
        ll mid = (lb + ub) / 2ll;

        ll count = 0ll;
        /*
        for(int i = 0; i < n; i++) {
            count += max(0ll, a[i] - mid + 1ll);
        }
        */
        for(auto iter = lower_bound(a.begin(), a.end(), mid); iter != a.end();
            iter++) {
            count += (*iter) - mid + 1ll;
        }
        if(count <= k) {
            ub = mid;
        } else { // count > k
            lb = mid;
        }
    }
    // cout << ub << endl;
    if(ub == 0ll) {
        ll ans = 0ll;
        for(auto e : a) {
            ans += acc(e, e);
        }
        cout << ans << endl;
        return 0;
    }
    ll ans = 0ll;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] < ub)
            break;
        ans += acc(a[i], a[i] - ub + 1);
        k -= (a[i] - ub + 1);
        a[i] = ub - 1ll;
    }
    // cout << ub << endl;
    // cout << k << endl;
    for(int i = 0; i < n; i++) {
        if(a[i] == ub - 1ll && k-- > 0ll) {
            ans += (ub - 1ll);
        }
    }
    cout << ans << endl;

    return 0;
}
#endif
