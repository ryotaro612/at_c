#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> sum(n + 1, 0);
    for(int i = 0; i < n; i++)
        sum[i + 1] += a[i] + sum[i];

    ll ans = numeric_limits<ll>::max();
    for(int i = 1; i < n; i++) {
        ans = min(ans, abs(sum[i] - (sum[n] - sum[i])));
    }
    cout << ans << endl;
    return 0;
}
#endif