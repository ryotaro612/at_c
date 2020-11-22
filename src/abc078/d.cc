#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, ll z, ll w, vector<ll> a) {
    ll res = abs(a[n - 1] - w);
    if(n == 1)
        return res;

    return max(res, abs(a[n - 1] - a[n - 2]));
}
/*
int main() {
    int n;
    cin >> n;
    ll z, w;
    cin >> z >> w;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, z, w, a);
}
*/