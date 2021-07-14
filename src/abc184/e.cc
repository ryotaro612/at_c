#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000000;

typedef pair<int, int> P;

struct item {
    int h, w, cost;
};

int solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<vector<P>> warp(26, vector<P>());
    P start, goal;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
            char c = a[i][j] - 'a';
            if(0 <= c && c <= 25) {
                warp[c].push_back({i, j});
            } else if(a[i][j] == 'S') {
                start = {i, j};
            } else if(a[i][j] == 'G') {
                goal = {i, j};
            }
        }
    }
    vector<vector<int>> d(h, vector<int>(w, INF));
    queue<item> que;
    vector<bool> done(26, false);
    d[start.first][start.second] = 0;
    que.push({start.first, start.second, 0});
    while(!que.empty()) {
        item p = que.front();
        que.pop();
        if(d[p.h][p.w] < p.cost)
            continue;

        int next_cost = d[p.h][p.w] + 1;
        if(p.h > 0 && a[p.h - 1][p.w] != '#') {
            if(next_cost < d[p.h - 1][p.w]) {
                d[p.h - 1][p.w] = next_cost;
                que.push({p.h - 1, p.w, next_cost});
            }
        }
        if(p.w < w - 1 && a[p.h][p.w + 1] != '#') {
            if(next_cost < d[p.h][p.w + 1]) {
                d[p.h][p.w + 1] = next_cost;
                que.push({p.h, p.w + 1, next_cost});
            }
        }
        if(p.h < h - 1 && a[p.h + 1][p.w] != '#') {
            if(next_cost < d[p.h + 1][p.w]) {
                d[p.h + 1][p.w] = next_cost;
                que.push({p.h + 1, p.w, next_cost});
            }
        }
        if(0 < p.w && a[p.h][p.w - 1] != '#') {
            if(next_cost < d[p.h][p.w - 1]) {
                d[p.h][p.w - 1] = next_cost;
                que.push({p.h, p.w - 1, next_cost});
            }
        }
        int c = a[p.h][p.w] - 'a';
        if(0 <= c && c <= 25) {
            if(done[c])
                continue;
            done[c] = true;
            for(int i = 0; i < (int)warp[c].size(); i++) {
                P neigh = warp[c][i];
                if(next_cost < d[neigh.first][neigh.second]) {
                    d[neigh.first][neigh.second] = next_cost;
                    que.push({neigh.first, neigh.second, next_cost});
                }
            }
        }
    }

    if(d[goal.first][goal.second] == INF)
        return -1;
    return d[goal.first][goal.second];
}

#ifndef _LOCAL
int main() {
    cout << solve() << endl;
    return 0;
}
#endif