#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(int n, vector<ll> &x, vector<ll> &y) {
    ll res = 0ll;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                if((x[i] - x[k]) * (y[j] - y[k]) - (x[j] - x[k]) * (y[i] - y[k]) != 0)
                    res++;
            }
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    cout << solve(n, x, y) << endl;

    return 0;
}
#endif