#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll cur = h[0];
    for(int i = 1; i < n; i++) {
        if(cur < h[i]) {
            cur = h[i];
        } else {
            cout << cur << endl;
            return 0;
        }
    }
    cout << h[n - 1] << endl;
    return 0;
}
#endif