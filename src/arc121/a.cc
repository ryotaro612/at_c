#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<ll> x(n), y(n);

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    vector<pair<ll, int>> xp(n), yp(n);
    for(int i = 0; i < n; i++) {
        xp[i] = {x[i], i};
        yp[i] = {y[i], i};
    }
    sort(xp.begin(), xp.end());
    sort(yp.begin(), yp.end());

    set<int> points = {
        xp[0].second, xp[1].second, xp[n - 1].second, xp[n - 2].second,
        yp[0].second, yp[1].second, yp[n - 1].second, yp[n - 2].second,
    };
    vector<int> v(points.begin(), points.end());
    vector<ll> vals;
    for(int i = 0; i < (int)v.size() - 1; i++) {
        for(int j = i + 1; j < (int)v.size(); j++) {
            vals.push_back(max(abs(x[v[i]] - x[v[j]]), abs(y[v[i]] - y[v[j]])));
        }
    }
    sort(vals.begin(), vals.end(), greater<ll>());

    cout << vals[1] << endl;

    return 0;
}
#endif