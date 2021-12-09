#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, int m, int c, vector<vector<int>> &a, vector<int> &b) {
    int res = 0;
    rep(i, n) {
        int temp = 0;
        rep(j, m) { temp += a[i][j] * b[j]; }
        temp += c;
        if(temp > 0)
            res++;
    }
    return res;
}

#ifndef _debug
int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) { cin >> a[i][j]; }
    }
    cout << solve(n, m, c, a, b) << endl;

    return 0;
}
#endif