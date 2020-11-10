#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a) {
    vector<ll> sum(n, 0), m(n, 0);
    sum[0] = a[0];
    m[0] = max(m[0], sum[0]);

    for(int i = 1; i < n; i++) {
        sum[i] = a[i] + sum[i - 1];
        m[i] = max(sum[i], m[i - 1]);
    }
    ll c = 0, res = 0;
    for(int i = 0; i < n; i++) {
        res = max(res, c + m[i]);
        c += sum[i];
        // cout << sum[i] << " " << c << endl;
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
    cout << solve(n, a);
}
*/