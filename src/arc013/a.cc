#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, int m, int l, int p, int q, int r) {
    vector<int> ans = {
        (n / p) * (m / q) * (l / r), (n / p) * (m / r) * (l / q),
        (n / q) * (m / p) * (l / r), (n / q) * (m / r) * (l / p),
        (n / r) * (m / p) * (l / q), (n / r) * (m / q) * (l / p),
    };
    //rep(i, ans.size()) cout << ans[i] << endl;
    return *max_element(ans.begin(), ans.end());
}

#ifndef _debug
int main() {
    int n, m, l, p, q, r;
    cin >> n >> m >> l >> p >> q >> r;
    cout << solve(n, m, l, p, q, r) << endl;
    return 0;
}
#endif