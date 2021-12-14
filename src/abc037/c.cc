#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, int k, vector<ll> a) {
    vector<ll> sum(n + 1, 0ll);
    for(int i = 1; i < n + 1; i++) {
        sum[i] = a[i - 1] + sum[i - 1];
    }
    ll res = 0ll;
    for(int i = 0; i < n - k + 1; i++) {
        res += sum[i + k] - sum[i];
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, k, a) << endl;
}
#endif
