#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int n, vector<vector<bool>> f, vector<vector<ll>> p) {
    vector<int> f_bits(n);
    // cout << "doge ##" << endl;
    for(int i = 0; i < n; i++) {
        int f_bit = 0;
        for(int j = 0; j < 10; j++) {
            if(f[i][j]) {
                f_bit += 1 << j;
            }
        }
        f_bits[i] = f_bit;
    }
    ll res = -numeric_limits<ll>::max();
    // cout << "21doge ##" << endl;
    for(int i = 1; i < (1 << 10); i++) {
        // cout << "i: -> " << i << endl;
        ll temp = 0ll;
        for(int j = 0; j < n; j++) {
            // cout << "j-> " << j<< endl;
            bitset<10> bs(f_bits[j] & i);
            // cout << "j-> " << j<< endl;
            int count = bs.count();
            temp += p[j][count];
        }
        res = max(res, temp);
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int n;
    cin >> n;
    vector<vector<bool>> f(n, vector<bool>(10));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            int t;
            cin >> t;
            f[i][j] = t == 1 ? true : false;
        }
    }
    vector<vector<ll>> p(n, vector<ll>(11));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 11; j++) {
            cin >> p[i][j];
        }
    }
    cout << solve(n, f, p) << endl;
    return 0;
}
#endif