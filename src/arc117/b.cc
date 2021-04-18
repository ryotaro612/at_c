#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

static const ll MOD = 1000000007ll;

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0ll);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll res = 1ll;
    for(int i = 1; i <= n; i++) {
        res *= (a[i] - a[i - 1] + 1);
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
#endif