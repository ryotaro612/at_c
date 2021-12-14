#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef ONLINE_JUDGE
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> ab(n);

    for(int i = 0; i < n; i++) {
        ll a;
        int b;
        cin >> a >> b;
        ab[i] = {a, b};
    }
    sort(ab.begin(), ab.end());
    ll ans = 0;
    int c = 0;
    for(int i = 0; i < (int)ab.size(); i++) {
        int d = min(m - c, ab[i].second);
        ans += ab[i].first * d;
        c += d;
    }
    cout << ans << endl;
    return 0;
}
#endif