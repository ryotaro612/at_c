#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if(a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

ll solve(int n, vector<ll> a) {
    ll res = gcd(a[0], a[0]);
    for(int i = 1; i < n; i++) {
        res = gcd(max(a[i], res), min(a[i], res));
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
}
#endif