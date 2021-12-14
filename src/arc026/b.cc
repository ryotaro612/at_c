#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

string solve(ll n) {
    vector<ll> divisors = calc_divisors(n);

    ll sum = 0ll;
    for(int i = 0; i < (int)divisors.size() - 1; i++)
        sum += divisors[i];

    if(sum > n)
        return "Abundant";
    if(sum == n)
        return "Perfect";
    return "Deficient";
}

#ifdef ONLINE_JUDGE
int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
#endif