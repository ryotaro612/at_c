#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll x, string s) {

    for(auto ss : s) {
        if(ss == 'x') {
            if(x != 0)
                x--;
        } else {
            x++;
        }
    }
    return x;
}
/*
int main() {
    ll n, x;
    string s;
    cin >> n >> x >> s;
    cout << solve(n, x, s);
}
*/