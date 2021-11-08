#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll gcd(ll a, ll b) {
    if(b == 0ll)
        return a;
    else
        return gcd(b, a % b);
}

ll solve(int n, vector<ll> &x, vector<ll> &y) {
    set<pair<int, int>> res;
    rep(i, n) {
        rep(j, n) {
			if(i == j)
				continue;
            ll diff_x = abs(x[i] - x[j]);
            ll diff_y = abs(y[i] - y[j]);
			if(diff_x == 0ll) {
				if(y[i]-y[j] >= 0)
					res.insert({0, 1});
				else
					res.insert({0, -1});
				continue;
			} else if(diff_y == 0ll) {
				if(x[i]-x[j] >= 0)
					res.insert({1, 0});
				else
					res.insert({-1, 0});
				continue;
			}
            ll gcd_v = gcd(diff_x, diff_y);
            diff_x /= gcd_v;
            diff_y /= gcd_v;
            if(x[i] - x[j] < 0)
                diff_x = -diff_x;
            if(y[i] - y[j] < 0)
                diff_y = -diff_y;
            res.insert({diff_x, diff_y});
        }
    }
    return (ll)res.size();
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    cout << solve(n, x, y) << endl;
    return 0;
}
#endif