#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(m), y(m), balls(n, 1);
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    vector<bool> red(n, false);
    red[0] = true;
    for(int i = 0; i < m; i++) {
        if(red[x[i]]) {
            if(balls[x[i]] == 1) {
                red[x[i]] = false;
                balls[x[i]]--;
                balls[y[i]]++;
                red[y[i]] = true;
            } else { // 赤いボールと白いボールがある
                red[y[i]] = true;

                balls[x[i]]--;
                balls[y[i]]++;
            }
        } else { // 赤いボールない
            balls[x[i]]--;
            balls[y[i]]++;
        }
    }
    ll ans = 0ll;
    for(int i = 0; i < n; i++)
        if(red[i])
            ans++;
    cout << ans << endl;

    return 0;
}
#endif