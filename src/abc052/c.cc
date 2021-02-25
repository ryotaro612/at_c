#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll MOD = 1000000007ll;

vector<int> calc_divisor(int n) {
    vector<int> res;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i * i != n) {
                res.push_back(n / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

ll solve(ll n) {
    set<ll> temp;
    ll acc = 1;
    for(int i = 1; i <= n; i++) {
        acc *= i;
        acc %= MOD;
    }
    cout << calc_divisor(acc).size() << endl;
    return -1ll;
}
#ifndef _LOCAL
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif