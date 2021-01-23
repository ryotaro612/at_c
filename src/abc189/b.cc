#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(ll n, ll x, vector<ll> v, vector<ll> p) {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        ll alc = v[i] * p[i];
        if(sum + alc > (x * 100)) {
            return i + 1;
        }
        sum += alc;
    }
    return -1;
}
/*
int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n), p(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i] >> p[i];
    }
    cout << solve(n, x, v, p) << endl;
}
*/