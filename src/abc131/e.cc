#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<pair<int, int>> solve(int n, int k) {
    int pairs_num = (n - 1) * (n - 2) / 2;
    if(k > pairs_num)
        return {};
    vector<pair<int, int>> res;
    for(int i = 2; i <= n; i++) {
        res.push_back({i, 1});
    }
    for(int i = 2; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(pairs_num > k) {
                res.push_back({i, j});
                pairs_num--;
            } else {
                return res;
            }
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> res = solve(n, k);

    if(res.empty()) {
        cout << -1 << endl;
        return 0;
    }
    cout << (int)res.size() << endl;
    for(auto p : res) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
#endif