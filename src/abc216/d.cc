//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(int n, int m, vector<int> &k, vector<vector<int>> &a) {
    // count[i]はiが入っている筒
    vector<int> count(n, -1);
    queue<pair<int, int>> que;
    for(int i = 0; i < m; i++) {
        int ball = a[i][a[i].size() - 1];
        if(count[ball] == -1) {
            count[ball] = i;
        } else {
            que.push({count[ball], i});
        }
    }
    while(!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        a[p.first].pop_back();
        a[p.second].pop_back();
        if(a[p.first].size() > 0) {
            int ball = a[p.first][a[p.first].size() - 1];
            if(count[ball] == -1) {
                count[ball] = p.first;
            } else {
                que.push({count[ball], p.first});
            }
        }
        if(a[p.second].size() > 0) {
            int ball = a[p.second][a[p.second].size() - 1];
            if(count[ball] == -1) {
                count[ball] = p.second;
            } else {
                que.push({count[ball], p.second});
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if(a[i].size() > 0)
            return "No";
    }
    return "Yes";
}

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> a(m);
    for(int i = 0; i < m; i++) {
        cin >> k[i];
        vector<int> aa(k[i]);
        for(int j = 0; j < k[i]; j++) {
            cin >> aa[j];
            aa[j]--;
        }
        a[i] = aa;
    }
    cout << solve(n, m, k, a) << endl;
}
#endif
