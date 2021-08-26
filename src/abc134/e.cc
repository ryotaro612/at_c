#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll INF = 10000000000ll;

int solve(int n, vector<ll> &a) {
    vector<ll> dp(n, INF);

    for(int i = n - 1; i >= 0; i--) {
        vector<ll>::iterator iter = upper_bound(dp.begin(), dp.end(), a[i]);
        *iter = a[i];
    }
    return distance(dp.begin(), lower_bound(dp.begin(), dp.end(), INF));
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(n, a) << endl;
    return 0;
}
#endif