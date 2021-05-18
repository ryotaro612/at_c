#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _LOCAL
int main() {
    ll n, c, k, ans = 0ll;
    cin >> n >> c >> k;
    vector<ll> t(n);
    for(int i = 0; i < n; i++)
        cin >> t[i];

    sort(t.begin(), t.end());
    for(int i = n - 1; i >= 0;) {
        // cout << "i: " << i << endl;
        int bus = 1; // 今のバスに一緒にのれる人の数
        // i - busは例外防止
        while(i - bus >= 0 && bus < c) {
            // cout << i - bus << " -> " << t[i - bus] + k << endl;
            if(t[i] <= t[i - bus] + k) { // 乗れる
                bus++;
            } else { // 一緒には乗れない
                break;
            }
        }
        ans++;
        i -= bus;
    }
    cout << ans << endl;
    return 0;
}
#endif