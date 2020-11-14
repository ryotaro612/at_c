#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll x) {
    ll a = x / 500;
    ll res = 1000 * a;
    x %= 500; 
    return res + (x / 5) * 5;
}
/*
int main() {
    ll x;
    cin >> x; 
    cout << solve(x);
}
*/