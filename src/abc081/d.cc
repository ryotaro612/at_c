#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> solve(ll n, vector<ll> a) {
    ll p_max = 0, n_min = 0;
    ll p_index = -1, n_index = -1;
    for(ll i = 0; i < n; i++) {
        if(a[i] > 0) {
            if(a[i] > p_max) {
                p_index = i;
                p_max = a[i];
            }
        } else {
            if(a[i] < n_min) {
                n_index = i;
                n_min = a[i];
            }
        }
    }
    vector<pair<ll, ll>> res;
    if(p_max == 0 && n_min == 0) {
        return res;
    }
    if(abs(p_max) > abs(n_min)) {
        for(int i = 0; i < n; i++) {
            a[i] += p_max;
            res.push_back(make_pair(p_index + 1, i + 1));
        }
        a[0] += p_max;
        res.push_back(make_pair(p_index + 1, 1));
        for(int i = 1; i < n; i++) {
            res.push_back(make_pair(i, i + 1));
            a[i] += a[i - 1];
        }
    } else {
        for(int i = 0; i < n; i++) {
            a[i] += n_min;
            res.push_back(make_pair(n_index + 1, i + 1));
        }
        a[n - 1] += n_min;
        res.push_back(make_pair(n_index + 1, n));
        for(int i = n - 2; i >= 0; i--) {
            a[i] += a[i + 1];
            res.push_back(make_pair(i + 2, i + 1));
        }
    }
    return res;
}
/*
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<ll, ll>> res = solve(n, a);
    cout << res.size() << endl;
    for(auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
}
*/