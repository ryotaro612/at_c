#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

pair<ll, vector<ll>> loop(ll x, ll m) {
    vector<bool> exists(m + 1, false);
    vector<ll> res;
    ll temp = x;
    res.push_back(temp);
    exists[temp] = true;
    while(true) {
        temp = (temp * temp) % m;
        if(exists[temp]) {
            int index = 0;
            while(res[index] != temp)
                index++;
            return make_pair(index, res);
        }
        exists[temp] = true;
        res.push_back(temp);
    }
    // unreachable;
    return make_pair(-1ll, res);
}

ll solve(ll n, ll x, ll m) {
    pair<ll, vector<ll>> trail = loop(x, m);
    int loop_start = trail.first;
    vector<ll> path = trail.second;
    ll res = 0ll;
    for(int i = 0; i < loop_start && 0 < n; i++, n--)
        res += path[i];

    if(0 == n)
        return res;

    ll sum = 0ll;
    for(int i = loop_start; i < (int)path.size(); i++)
        sum += path[i];

    int loop_size = (int)path.size() - loop_start;

    res += (n / (ll)loop_size) * sum;
    n %= (ll)loop_size;

    for(int i = loop_start; 0 < n; i++, n--)
        res += path[i];

    return res;
}

#ifndef _LOCAL
int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    cout << solve(n, x, m) << endl;
    return 0;
}
#endif