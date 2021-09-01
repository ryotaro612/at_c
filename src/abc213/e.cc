#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct P {
    int cost, h, w;

    bool operator<(const P &that) const { return cost < that.cost; };
    bool operator>(const P &that) const { return cost > that.cost; };
};

ll solve(int h, int w, vector<string> s) {
    vector<vector<int>> c(h, vector<int>(w, 10000000));

    priority_queue<P, vector<P>, greater<P>> que;

    que.push({0, 0, 0});
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        if(p.h < 0 || p.h >= h || p.w < 0 || p.w >= w || p.cost >= c[p.h][p.w])
            continue;
        c[p.h][p.w] = p.cost;
        if(p.h > 0) {
            int n_h = p.h - 1, n_w = p.w;
            if(s[n_h][n_w] == '.') {
                que.push({p.cost, n_h, n_w});
            } else {
                for(int i = -1; i < 2; i++) {
                    que.push({p.cost + 1, n_h, n_w + i});
                    que.push({p.cost + 1, n_h - 1, n_w + i});
                }
            }
        }
        if(p.w < w - 1) {
            int n_h = p.h, n_w = p.w + 1;
            if(s[n_h][n_w] == '.') {
                que.push({p.cost, n_h, n_w});
            } else {
                for(int i = -1; i < 2; i++) {
                    que.push({p.cost + 1, n_h + i, n_w});
                    que.push({p.cost + 1, n_h + i, n_w + 1});
                }
            }
        }
        if(p.h < h - 1) {
            int n_h = p.h + 1, n_w = p.w;
            if(s[n_h][n_w] == '.') {
                que.push({p.cost, n_h, n_w});
            } else {
                for(int i = -1; i < 2; i++) {
                    que.push({p.cost + 1, n_h, n_w + i});
                    que.push({p.cost + 1, n_h + 1, n_w + i});
                }
            }
        }
        if(p.w > 0) {
            int n_h = p.h, n_w = p.w - 1;
            if(s[n_h][n_w] == '.') {
                que.push({p.cost, n_h, n_w});
            } else {
                for(int i = -1; i < 2; i++) {
                    que.push({p.cost + 1, n_h + i, n_w});
                    que.push({p.cost + 1, n_h + i, n_w - 1});
                }
            }
        }
    }
    return c[h - 1][w - 1];
}

#ifndef _debug
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