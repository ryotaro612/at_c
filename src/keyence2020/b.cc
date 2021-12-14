#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<ll> x, vector<ll> l) {
    vector<pair<ll, ll>> lr(n);
    for(int i = 0; i < n; i++) {
        lr[i] = make_pair(l[i] + x[i], x[i] - l[i]);
    }
    sort(lr.begin(), lr.end());

    int ans = 1, t = lr[0].first;
    for(int i = 1; i < n; i++) {
        if(t <= lr[i].second) {
            ans++;
            t = lr[i].first;
        }
    }
    return ans;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), l(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> l[i];

    cout << solve(n, x, l) << endl;
}
#endif