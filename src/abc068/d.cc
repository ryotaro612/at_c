#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> solve(ll k) {
    ll n = 50;
    ll d = k / n;
    ll base = n - 1 + d;
    ll m = k % n;
    vector<ll> res(n);
    for(int i = 0; i < m; i++) {
        res[i] = base + n - m + 1;
    }
    for(int i = m; i < n; i++) {
        res[i] = base - m;
    }

    return res;
}
/*
int main() {
    ll k;
    cin >> k;
    vector<ll> res = solve(k);
    cout << res.size() << endl;
    for(int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if(i == (int)res.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}
*/