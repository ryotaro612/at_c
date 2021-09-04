#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

#ifndef _debug
int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = numeric_limits<int>::max();
    rep(i, max(x, y) + 1) {
        // i枚のビザをABピザ2枚買って用意する。
        // abピザの料金
        int temp = c * 2 * i;
        if(x - i > 0) {
            temp += a * (x - i);
        }
        if(y - i > 0) {
            temp += b * (y - i);
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}
#endif