#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

string solve(int n, vector<int> &t, vector<int> &x, vector<int> &y) {

    int time = 0, c_x = 0, c_y = 0;
    rep(i, n) {
        int dist = abs(c_x - x[i]) + abs(c_y - y[i]);
        if(time + dist > t[i]) {
            return "No";
        } else { // time + dist <= t[i];
            if((t[i] - time + dist) % 2 != 0) {
                return "No";
            }
        }

        c_x = x[i];
        c_y = y[i];
        time = t[i];
    }

    return "Yes";
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> t(n), x(n), y(n);
    rep(i, n) cin >> t[i] >> x[i] >> y[i];
    cout << solve(n, t, x, y) << endl;
    return 0;
}
#endif
