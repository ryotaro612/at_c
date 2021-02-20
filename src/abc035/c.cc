#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll n, ll q, vector<ll> l, vector<ll> r) {
    vector<ll> res(n + 1, 0);
    for(int i = 0; i < q; i++) {
        res[l[i] - 1] += 1;
        res[r[i]] -= 1;
    }
    for(int i = 1; i < n + 1; i++) {
        res[i] += res[i - 1];
    }
    string res_str = "";
    for(int i = 0; i < n; i++) {

        res_str.push_back(res[i] % 2 == 0 ? '0' : '1');
    }
    return res_str;
}
#ifndef _LOCAL
int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> l(q), r(q);
    for(int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
    }
    cout << solve(n, q, l, r) << endl;
}
#endif