#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(ll q, vector<ll> l, vector<ll> r) {
    int mx = 100002;
    vector<bool> p(mx, true);
    p[0] = p[1] = false;
    for(int i = 2; i <= mx; i++) {
        if(p[i]) {
            for(int j = i * 2; j <= mx; j += i) {
                p[j] = false;
            }
        }
    }

    vector<ll> sum(mx, 0);
    for(int i = 3; i < mx; i++) {
        if(p[i] && p[(i + 1) / 2]) {
            sum[i + 1] = sum[i] + 1;
        } else {
            sum[i + 1] = sum[i];
        }
    }
    vector<ll> res;
    for(int i = 0; i < q; i++) {
        res.push_back(sum[r[i] + 1] - sum[l[i]]);
    }
    return res;
}
/*
int main() {
    ll q;
    cin >> q;
    vector<ll> l(q), r(q);
    for(int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
    }
    vector<ll> res = solve(q, l, r);
    for(auto rr : res) {
        cout << rr << endl;
    }
}
*/