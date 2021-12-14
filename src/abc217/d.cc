#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
    ll l;
    int q;
    cin >> l >> q;
    vector<int> c(q), x(q);
    rep(i, q) cin >> c[i] >> x[i];

    set<ll> cut;
    cut.insert(0ll);
    cut.insert(l);

    rep(i, q) {
        if(c[i] == 1) {
            cut.insert(x[i]);
        } else {
            auto left_iter = cut.lower_bound(x[i]);
            ll left = *(--left_iter);
            ll right = *(cut.upper_bound(x[i]));
            //cout << i << " " << left << " " << right << endl;
            cout << right - left << endl;
        }
    }

    return 0;
}
#endif
