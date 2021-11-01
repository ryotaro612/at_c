#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, vector<int> &v, vector<int> &c) {
    int res = 0;
    rep(i, 1 << n) {
        int x = 0, y = 0;
        rep(j, n) {
            if(i & (1 << j)) {
                x += v[j];
                y += c[j];
            }
        }

        res = max(res, x - y);
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> v(n), c(n);
    rep(i, n) cin >> v[i];
    rep(i, n) cin >> c[i];
    cout << solve(n, v, c) << endl;
    return 0;
}
#endif