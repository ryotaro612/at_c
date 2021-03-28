#ifdef _LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> calc_ors(vector<vector<ll>> &cands) {
    vector<ll> res;
    for(int i = 0; i < (int)cands.size(); i++) {
        if((int)cands[i].size() == 0)
            continue;
        ll temp = cands[i][0];
        for(int j = 1; j < (int)cands[i].size(); j++) {
            temp = temp | cands[i][j];
        }
        res.push_back(temp);
    }
    return res;
}

ll calc_xor(vector<ll> &cands) {
    ll res = cands[0];
    for(int i = 1; i < (int)cands.size(); i++) {
        res = res ^ cands[i];
    }
    return res;
}

ll solve(int n, vector<ll> a) {
    ll res = 1000000000000000000ll;
    for(ll i = 0; i < (1 << (n - 1)); i++) {
        //cout << i << endl;
        vector<vector<ll>> cands(1);
        for(int j = 0; j < n; j++) {
            //cout << "j " << j << endl;
            cands[cands.size() - 1].push_back(a[j]);
            //cout << "tail j " << j << endl;
            if(j != n - 1) {
                if(i & (1 << j)) {
                    cands.push_back({});
                }
            }
        }
        //cout << "count cand" << endl;
        vector<ll> ors = calc_ors(cands);
        //cout << i << " ors" << endl;
        ll temp = calc_xor(ors);
        //cout << i << " xor" << endl;
        res = min(temp, res);
    }
    return res;
}

#ifndef _LOCAL
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, a) << endl;
    return 0;
}
#endif