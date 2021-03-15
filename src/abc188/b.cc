#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string solve(int n, vector<ll> a, vector<ll> b) {
    ll res = 0ll;
    for(int i = 0; i < n; i++) {
        res += (a[i] * b[i]);
    }
    return res == 0ll ? "Yes" : "No";
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    cout << solve(n, a, b) << endl;
    return 0;
}
#endif
