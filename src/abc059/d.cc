#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll x, ll y) {
    return abs(x-y) <= 1 ? "Brown" : "Alice";
}
/*
int main() {
    ll x, y;
    cin >> x >> y;

    cout << solve(x, y);
}
*/