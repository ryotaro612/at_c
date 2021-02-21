#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> div(ll x) {
    vector<int> res;
    if(x == 0) {
        res.push_back(0);
        return res;
    }
    while(x != 0) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}

ll f(ll x) {
    vector<int> digits = div(x);
    sort(digits.begin(), digits.end(), greater<int>());
    ll one_v = 0ll;
    for(auto o : digits) {
        one_v *= 10ll;
        one_v += o;
    }
    sort(digits.begin(), digits.end());
    ll two_v = 0ll;
    for(auto d : digits) {
        two_v *= 10ll;
        two_v += d;
    }
    return one_v - two_v;
}

ll solve(ll n, ll k) {
    ll res = n;
    for(int i = 0; i < k; i++) {
        res = f(res);
    }
    return res;
}

#ifndef _LOCAL
int main() {
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
}
#endif