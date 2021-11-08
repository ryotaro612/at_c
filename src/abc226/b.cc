#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int n, vector<vector<ll>> &a) {
    sort(a.begin(), a.end(), [](const vector<ll> &l, const vector<ll> &r) {
        if(l.size() != r.size()) {
            return l.size() < r.size();
        }
        rep(i, l.size()) {
            if(l[i] != r[i])
                return l[i] < r[i];
        }
        return false;
    });

    // rep(i, n) {
    // 	rep(j, a[i].size()) {
    // 		cout << a[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    int res = 1;
    vector<ll> prev;
    for(int i = 1; i < n; i++) {
        if(a[i - 1].size() != a[i].size())
            res++;
        else {
            bool ok = true;
            rep(j, a[i].size()) {
                if(a[i - 1][j] != a[i][j]) {
                    ok = false;
                    break;
                }
            }
            if(!ok)
                res++;
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    vector<vector<ll>> a;
    rep(i, n) {
        cin >> l[i];
        vector<ll> b(l[i]);
        rep(j, l[i]) { cin >> b[j]; }
        a.push_back(b);
    }
    cout << solve(n, a) << endl;
    return 0;
}
#endif