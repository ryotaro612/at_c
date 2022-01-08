#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

optional<ll> rec(int index, string chunk, int diff, string &s) {
    if(index == (int)s.size()) {
        return stoll(chunk);
    }
    int a = (chunk[chunk.size() - 1] - '0') + diff;
    if(0 <= a && a <= 9) {
        chunk.push_back(a + '0');
        return rec(index + 1, chunk, diff, s);
    }
    return nullopt;
}

ll solve(ll x) {
    string x_s = to_string(x);
    vector<ll> cands;
    for(int i = x_s[0] - '0'; i < 10; i++) {
        for(int j = -9; j <= 9; j++) {
            optional<ll> a = rec(1, to_string(i), j, x_s);
            if(a != nullopt)
                cands.push_back(a.value());
        }
    }
    string sentinel((int)x_s.size() + 1, '1');
    cands.push_back(stoll(sentinel));
    sort(cands.begin(), cands.end());
    return *lower_bound(cands.begin(), cands.end(), x);

}

#ifdef ONLINE_JUDGE
int main() {
    ll x;
    cin >> x;
    cout << solve(x) << endl;
    return 0;
}
#endif