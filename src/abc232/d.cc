#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int solve(int h, int w, vector<string> &grid) {
    int inf = 1 << 30;
    vector<vector<int>> cost(h, vector<int>(w, inf));
    cost[0][0] = 0;
    queue<pair<int, int>> que;
    que.push({0, 0});
    while(!que.empty()) {
        pair<int, int> point = que.front();
        int r = point.first, c = point.second;
        que.pop();
        // cout << r << " " << c << endl;

        if(r < h - 1 && grid[r + 1][c] == '.' && cost[r + 1][c] == inf) {
            cost[r + 1][c] = cost[r][c] + 1;
            que.push({r + 1, c});
        }
        if(c < w - 1 && grid[r][c + 1] == '.' && cost[r][c + 1] == inf) {
            cost[r][c + 1] = cost[r][c] + 1;
            que.push({r, c + 1});
        }
    }
    int res = 0;
    rep(i, h) {
        rep(j, w) {
            if(cost[i][j] < inf) {
                res = max(cost[i][j], res);
            }
        }
    }
    return res + 1;
}

#ifdef ONLINE_JUDGE
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];
    cout << solve(h, w, grid) << endl;
    return 0;
}
#endif