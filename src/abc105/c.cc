#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll n) {
    if(n == 0)
        return "0";
    vector<ll> rev;
    ll a = n, b;
    while(true) {
        if(a > 0 || a % (-2) == 0) {
            ll aa = a / (-2);
            b = a % (-2);
            a = aa;
        } else {
            a = (a - 1) / (-2);
            b = 1;
        }

        rev.push_back(b);
        if(a == 1) {
            rev.push_back(1);
            break;
        }
    }
    string res;
    for(int i = (int)rev.size() - 1; i >= 0; i--) {
        res += rev[i] == 0 ? '0' : '1';
    }

    return res;
}
/*
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}
*/