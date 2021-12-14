// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
int H, W;

vector<vector<int>> dp;

void dfs(int i, int j, int count, bool prev_black) {
    if(dp[i][j] <= count)
        return;
    if(i == H - 1 && j == W - 1) {
        if(prev_black) {
            dp[i][j] = min(count, dp[i][j]);
        } else {
            if(grid[i][j] == '#')
                dp[i][j] = min(count + 1, dp[i][j]);
            else
                dp[i][j] = min(count, dp[i][j]);
        }
        return;
    }
    if(grid[i][j] == '.') {
        prev_black = false;
    } else {
        if(!prev_black)
            count++;
        prev_black = true;
    }
    if(dp[i][j] <= count)
        return;
    dp[i][j] = count;
    if(i < H - 1)
        dfs(i + 1, j, count, prev_black);
    if(j < W - 1)
        dfs(i, j + 1, count, prev_black);
    return;
}

int solve(int h, int w, vector<string> area) {
    grid.resize(h);
    dp.resize(h);
    for(int i = 0; i < h; i++)
        dp[i] = vector<int>(w, numeric_limits<int>::max());
    H = h;
    W = w;
    for(int i = 0; i < h; i++)
        grid[i] = area[i];
    dfs(0, 0, 0, false);
    /*
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    */
    return dp[H - 1][W - 1];
}

#ifdef ONLINE_JUDGE
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> area(h);
    for(int i = 0; i < h; i++)
        cin >> area[i];

    cout << solve(h, w, area) << endl;
    return 0;
}
#endif