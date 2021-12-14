#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const ll MOD = 1000000007ll;

vector<ll> count_neighbors(string &line) {
    int n = line.size();
    vector<ll> res(n, 0ll);
    ll count = 0ll;
    rep(i, n) {
        if(line[i] == '#') {
            count = 0ll;
        } else {
            count++;
            res[i] = count;
        }
    }
    count = 0ll;
    for(int i = n - 1; i >= 0; i--) {
        if(line[i] == '#')
            count = 0;
        else {
            res[i] += count;
            count++;
        }
    }
    return res;
}
ll pow(ll x, ll n) {
    ll res = 1ll;
    while(n > 0) {
        if(n & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    return res;
}

ll solve(int h, int w, vector<string> &s) {
    vector<vector<ll>> lights(h);
    rep(i, h) {
        vector<ll> delta = count_neighbors(s[i]);
        lights[i] = delta;
    }
    rep(j, w) {
        string line;
        rep(i, h) { line.push_back(s[i][j]); }
        vector<ll> delta = count_neighbors(line);
        rep(i, h) { lights[i][j] += delta[i]; }
    }
    ll all_lamps = 0ll;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '.') {
                lights[i][j]--;
                all_lamps++;
            }
        }
    }
    ll res = 0ll;
    rep(i, h) {
        rep(j, w) {
            res += ((pow(2ll, lights[i][j]) - 1ll + MOD) % MOD) *
                   pow(2ll, all_lamps - lights[i][j]) % MOD;
            res %= MOD;
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    cout << solve(h, w, s) << endl;
    return 0;
}
#endif