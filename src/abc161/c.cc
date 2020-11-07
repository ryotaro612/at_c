#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k) {
    ll nn = n % k;

    return min(nn, abs(nn - k));
}
/*
int main() {
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k);
}
*/