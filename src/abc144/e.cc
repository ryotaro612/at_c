#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n, ll k, vector<ll> &a, vector<ll> &f) {
    sort(a.begin(), a.end(), greater<ll>());
    sort(f.begin(), f.end());
    ll lb = -1ll, ub = 1000000000001ll;
	/*
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << f[i] << " ";
    cout << endl;
	*/

    while(ub - lb > 1) {
        ll mid = (lb + ub) / 2ll;
        ll count = 0ll;
        for(int i = 0; i < n; i++) {
            if(a[i] * f[i] > mid) {
                count += a[i] - mid / f[i];
            }
        }
        //cout << "mid: " << mid << " " << count << endl;
        if(count <= k)
            ub = mid;
        else
            lb = mid;
    }
    return ub;
}

#ifndef _debug
int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> f[i];
    cout << solve(n, k, a, f) << endl;
    return 0;
}
#endif