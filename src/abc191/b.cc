#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(int n, ll x, vector<ll> a) {
    vector<ll> res;
    for(auto aa: a) {
        if(aa != x) {
            res.push_back(aa);
        }
    }
    return res;
}
/*
int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> res = solve(n, x, a);
    for(int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if(i == (int)res.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    return 0;
}
*/