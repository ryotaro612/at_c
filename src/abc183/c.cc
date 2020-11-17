#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(ll n, ll k, vector<vector<ll>> t) {
    int res = 0;
    vector<ll> p(n - 1);
    for(int i = 1; i < n; i++) {
        p[i - 1] = i;
    }
    do {
        ll temp = t[0][p[0]];
        for(int i = 1; i < n - 1; i++) {
            temp += t[p[i - 1]][p[i]];
        }
        temp += t[p[n - 2]][0];
        if(temp == k) {
            res++;
        }
    } while(next_permutation(p.begin(), p.end()));
    return res;
}
/*
int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> t(n, vector<ll>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    cout << solve(n, k, t);
}
*/