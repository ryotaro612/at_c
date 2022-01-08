#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long double ld;
typedef long long ll;

ld solve(int n, vector<int> &x, vector<int> &y) {
    ld res = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ld xx = (ld)x[i] - (ld)x[j];
            ld yy = (ld)y[i] - (ld)y[j];

            res = max(sqrt(xx * xx + yy * yy), res);
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    cout << fixed << setprecision(12) << solve(n, x, y) << endl;
    return 0;
}
#endif