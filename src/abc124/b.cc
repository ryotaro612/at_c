#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, vector<int> &h) {
    int mx = 0, res = 0;
    rep(i, n) {
        if(mx <= h[i])
            res++;
        mx = max(mx, h[i]);
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    cout << solve(n, h) << endl;
    return 0;
}
#endif