#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll r, ll c, ll k, ll n, vector<ll> rv, vector<ll> cv) {
    // number of candies per column or row.
    vector<ll> rn(r, 0), cn(c, 0);
    for(int i = 0; i < n; i++) {
        rn[rv[i] - 1] += 1;
    }
    for(int i = 0; i < n; i++) {
        cn[cv[i] - 1] += 1;
    }
    vector<ll> candy_num_to_column_num(n + 1, 0);
    for(int i = 0; i < c; i++) {
        candy_num_to_column_num[cn[i]] += 1;
    }
    ll res = 0;
    for(int i = 0; i < r; i++) {
        ll number_of_candies_column_should_have = k - rn[i];
        if(number_of_candies_column_should_have >= 0) {
            res +=
                candy_num_to_column_num[number_of_candies_column_should_have];
        }
    }

    for(int i = 0; i < n; i++) {
        ll candies = rn[rv[i] - 1] + cn[cv[i] - 1];
        if(candies == k) {
            res--;
        } else if(candies == k + 1) {
            res++;
        }
    }
    return res;
}
/*
int main() {
    ll r, c, k, n;
    cin >> r >> c >> k >> n;
    vector<ll> rv(n), cv(n);
    for(int i = 0; i < n; i++) {
        cin >> rv[i] >> cv[i];
    }

    cout << solve(r, c, k, n, rv, cv) << endl;
}
*/