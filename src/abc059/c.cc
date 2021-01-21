#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a) {
    ll res = numeric_limits<ll>::max();
    for(int pn = 0; pn < 2; pn++) {
        ll sum = 0, count = 0;
        for(int i = 0; i < n; i++) {
            ll temp = sum + a[i];
            cout << i << " -> current sum: " << temp << endl;
            if((pn == 0 && temp > 0) || (pn == 1 && temp < 0)) {
                sum = temp;
                continue;
            } else {
                ll delta = abs(temp) + 1;
                count += delta;
                sum = temp + delta * (pn == 0 ? 1 : -1);
            }
            cout << "modified -> " << sum << " current " << count << endl;
        }
        res = min(count, res);
        cout << " ====== " << endl;
    }
    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
}
*/