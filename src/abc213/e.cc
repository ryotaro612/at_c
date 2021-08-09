#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll solve(int h, int w, vector<string> s) {
    vector<vector<int>> c(h, vector<int>(w, -1));

    priority_queue<pair<pair<int, int>, pair<int, int>>,
                   vector<pair<pair<int, int>, pair<int, int>>>,
                   greater<pair<pair<int, int>, pair<int, int>>>>
        que;

    que.push({{0, 0}, {0, 0}});
    ll ans;
    while(!que.empty()) {
        pair<pair<int, int>, pair<int, int>> p = que.top();
        que.pop();
        int cost = p.first.first;
        int wall = p.first.second;
        int hh = p.second.first;
        int ww = p.second.second;

        if(hh > 0 && c[hh - 1][ww] == -1) {
            if(s[hh - 1][ww] == '.') {
                que.push({{cost, 0}, {hh - 1, ww}});
            } else {
                que.push({{cost, 0}, {hh - 1, ww}});
			}
        }
    }
    return ans;
}

#ifndef _LOCAL
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++)
        cin >> s[i];

    cout << solve(h, w, s) << endl;
    return 0;
}
#endif