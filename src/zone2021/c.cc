#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(int n, vector<vector<ll>> &av) {
    ll lb = 0ll, ub = (ll)10e9 + 1ll;
    while(ub - lb > 1) {
        ll mid = (ub + lb) / 2ll;
        unordered_set<int> patterns;
        for(auto scores : av) {
            int pattern = 0;
            for(auto score : scores) {
                pattern = pattern << 1;
                pattern |= score >= mid;
            }
            patterns.insert(pattern);
        }
        // cout << " --- " << endl;
        // cout << "mid: " << mid << endl;
        // for(auto s : patterns) {
        //     cout << s << endl;
        // }
        // cout << " --- " << endl;
        vector<int> scores(patterns.begin(), patterns.end());
        int size = scores.size();
        bool ok = false;
        if(size == 1) {
            ok = scores[0] == 31;
        } else if(size == 2) {
            rep(i, size - 1) {
                for(int j = i + 1; j < size; j++) {
                    if((scores[i] | scores[j]) == 31) {
                        ok = true;
                    }
                }
            }
        } else {
            rep(i, size - 2) {
                for(int j = i + 1; j < size - 1; j++) {
                    for(int k = j + 1; k < size; k++) {
                        if((scores[i] | scores[j] | scores[k]) == 31) {
                            ok = true;
                        }
                    }
                }
            }
        }
        if(ok)
            lb = mid;
        else
            ub = mid;
    }
    return lb;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(5));
    rep(i, n) { cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4]; }
    cout << solve(n, a) << endl;
    return 0;
}
#endif