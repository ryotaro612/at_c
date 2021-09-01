#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), k(q);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < q; i++)
        cin >> k[i];

    for(auto kk : k) {

        ll lb = 0ll, ub = numeric_limits<ll>::max();
        while(ub - lb > 1) {
            ll mid = (ub + lb) / 2ll;
            auto it = lower_bound(a.begin(), a.end(), mid);
            ll index = it - a.begin();
            if(kk < mid - index) {
                ub = mid;
            } else {
                lb = mid;
            }
        }
        cout << lb << endl;
    }
    return 0;
}
#endif