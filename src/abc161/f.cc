#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

// クイックソート
vector<ll> calc_divisors(ll n) {
    vector<ll> res;
    for(ll i = 1ll; i * i <= n; i++) {
        if(n % i == 0ll) {
            res.push_back(i);
            if(i * i != n)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

bool check(ll k, ll n) {
    while(k < n) {
        while(n % k == 0ll) {
            n /= k;
        }
        n -= n / k * k;
    }
    return n == 1ll;
}

/**
 * n == kは必ず
 * 互いに疎な数であればいいわけではない(5, 3)とか
 * 2乗以下で考えるから10^12になっている?
 * 2倍や2乗以下かをみる?
 * 2乗よりうえはn-1だけ?
 * 割り算は1-から全部計算できる
 *
 * n = 2 -> k = 2
 * n = 3 -> k = 2, 3
 * n = 4 -> k = 2, 3, 4
 * n = 5 -> k = 2, 4, 5
 * n = 6 -> k = 2, 5, 6
 * n = 7 -> k = 2, 3, 6, 7
 */
ll solve(ll n) {
    vector<ll> divisors = calc_divisors(n - 1);
    unordered_set<ll> res(divisors.begin(), divisors.end());
    res.erase(1ll);
    res.insert(n);
    for(ll i = 2ll; i * i <= n; i++) {
        if(res.find(i) == res.end()) {
            if(check(i, n)) {
                res.insert(i);
            }
        }
    }

    return res.size();
}

#ifndef _debug
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif