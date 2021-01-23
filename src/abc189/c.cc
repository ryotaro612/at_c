#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(ll n, vector<ll> a) {
    ll res = 0;
    for(ll l = 0; l < n; l++) {
        ll mini = a[l];
        for(ll r = l; r < n; r++) {
            if(mini > a[r]) {
                mini = a[r];
            }
            res = max(res, mini * (r - l + 1));
        }
    }
    return res;
}
/*
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(n, a) << endl;
}
*/