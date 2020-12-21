#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a) {
    sort(a.begin(), a.end());

    vector<ll> sum(n);
    sum[0] = a[0];
    for(int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    ll res = 0;
    for(int i = 1; i <= n - 1; i++) {
        res += (sum[n - 1] - sum[i-1]) - (n - i) * a[i - 1];
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