#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ld solve(int n, vector<ld> &x, vector<string> &u) {
    ld res = 0;
    rep(i, n) {
        if(u[i] == "JPY")
            res += x[i];
        else {
            res += x[i] * 380000.0;
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ld> x(n);
    vector<string> u(n);
    rep(i, n) cin >> x[i] >> u[i];
    cout << fixed << setprecision(12) << solve(n, x, u) << endl;
}
#endif