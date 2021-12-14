#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(int h, int w, vector<vector<ll>> &a) {
    for(int i = 0; i < h - 1; i++) {
        for(int j = i + 1; j < h; j++) {
            for(int k = 0; k < w - 1; k++) {
                for(int l = k + 1; l < w; l++) {
                    if(a[i][k] + a[j][l] <= a[j][k] + a[i][l])
                        continue;
                    else
                        return "No";
                }
            }
        }
    }
    return "Yes";
}

#ifdef ONLINE_JUDGE
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h) {
        rep(j, w) { cin >> a[i][j]; }
    }
    cout << solve(h, w, a) << endl;
    return 0;
}
#endif