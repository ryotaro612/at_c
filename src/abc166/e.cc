#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, vector<ll> a) {
    map<ll, ll> m;
    for(int i = 0; i < n; i++)
        m[i + 1 - a[i]]++;
    ll res = 0ll;
    for(int i = 0; i < n - 1; i++)
        res += m[a[i] + i + 1];
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