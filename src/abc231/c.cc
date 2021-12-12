#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<int> solve(int n, int q, vector<ll> &a, vector<ll> &x) {
    sort(a.begin(), a.end());
    vector<int> res;
    for(auto e : x) {
        auto iter = lower_bound(a.begin(), a.end(), e);
        res.push_back(a.end() - iter);
        //cout << " doge " << endl;
    }
    return res;
}

#ifndef _debug
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), x(q);
    rep(i, n) cin >> a[i];
    rep(i, q) cin >> x[i];
    vector<int> res = solve(n, q, a, x);
    for(auto e : res)
        cout << e << endl;

    return 0;
}
#endif