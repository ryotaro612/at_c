#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, vector<ll> a, vector<ll> b) {
    ll sum = 0;
    vector<ll> diff(n);
    for(int i = 0; i < n; i++) {
        sum += a[i];
        diff[i] = 2 * a[i] + b[i];
    }
    sort(diff.begin(), diff.end(), greater<ll>());
    ll res = 0;
    for(int i = 0; i < n; i++) {
        if(sum < 0) {
            return res;
        }
        sum -= diff[i];
        res++;
    }
    // unreachable
    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << solve(n, a, b);
    return 0;
}
*/