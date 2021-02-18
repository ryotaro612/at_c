#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y, cost;
};
int solve(int r, int c, int sy, int sx, int gy, int gx, vector<string> cv) {
    sy--;
    sx--;
    gy--;
    gx--;
    queue<point> que;
    que.push({sx, sy, 0});
    vector<vector<bool>> used(r, vector<bool>(c, false));
    used[sy][sx] = true;
    while(!que.empty()) {
        point p = que.front();
        que.pop();
        //cout << "at: " << p.y << " " << p.x << " -> " << cv[p.y][p.x] << endl;
        if(p.x == gx && p.y == gy)
            return p.cost;

        int cost = p.cost + 1;
        if(p.y != 0 && cv[p.y - 1][p.x] == '.' && !used[p.y - 1][p.x]) {
            used[p.y - 1][p.x] = true;
            que.push({p.x, p.y - 1, cost});
        }
        if(p.x < c - 1 && cv[p.y][p.x + 1] == '.' && !used[p.y][p.x + 1]) {
            used[p.y][p.x + 1] = true;
            que.push({p.x + 1, p.y, cost});
        }
        if(p.y < r - 1 && cv[p.y + 1][p.x] == '.' && !used[p.y + 1][p.x]) {
            used[p.y + 1][p.x] = true;
            que.push({p.x, p.y + 1, cost});
        }
        if(p.x > 0 && cv[p.y][p.x - 1] == '.' && !used[p.y][p.x - 1]) {
            used[p.y][p.x - 1] = true;
            que.push({p.x - 1, p.y, cost});
        }
    }
    return -1;
}
/*
int main() {
    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    vector<string> cv(r);
    for(int i=0;i<r;i++) {
        cin >> cv[i];
    }
    cout << solve(r, c, sy, sx, gy, gx, cv) << endl;
    return 0;
}
*/