#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef _debug
int main() {
    int n, k;
    ll m, r;
    cin >> n >> k >> m >> r;
    vector<ll> s(n - 1);
    for(int i = 0; i < n - 1; i++)
        cin >> s[i];
    sort(s.begin(), s.end(), greater<ll>());

    ll sum = 0ll;
    for(int i = 0; i < k - 1; i++)
        sum += s[i];

    ll t = k * r;
    if(t - sum > m) {
        cout << -1 << endl;
        return 0;
    }
    if(sum >= t) {
        cout << 0 << endl;
        return 0;
    }
    if(k - 1 <= n - 2) {
        if(t <= sum + s[k - 1]) {
            cout << 0 << endl;
            return 0;
        };
    }
    cout << t - sum << endl;
    return 0;
}
#endif