#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<string, string> solve(int r, vector<int> x, vector<int> y) {
    if(y[0] + r <= y[2] && x[0] + r <= x[2] && y[0] - r >= y[1] &&
       x[0] - r >= x[1]) {
        return make_pair("NO", "YES");
    }
    if((x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]) <= r * r &&
       (x[2] - x[0]) * (x[2] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]) <= r * r &&
       (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]) <= r * r &&
       (x[1] - x[0]) * (x[1] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]) <= r * r) {
        return make_pair("YES", "NO");
    }

    return make_pair("YES", "YES");
}

#ifndef _LOCAL
int main() {
    int r;
    vector<int> x(3), y(3);
    cin >> x[0] >> y[0] >> r >> x[1] >> y[1] >> x[2] >> y[2];

    pair<string, string> ans = solve(r, x, y);
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}
#endif