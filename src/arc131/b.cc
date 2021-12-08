#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

vector<string> solve(int h, int w, vector<string> grid) {
    rep(i, h) {
        rep(j, w) {
            // cout << i << " " << j << endl;
            if(grid[i][j] != '.')
                continue;
            vector<bool> usable(5, true);
            if(i > 0 && grid[i - 1][j] != '.')
                usable[grid[i - 1][j] - '1'] = false;
            // cout << i << " " << j << endl;
            if(j < w - 1 && grid[i][j + 1] != '.')
                usable[grid[i][j + 1] - '1'] = false;
            // cout << i << " " << j << endl;
            if(i < h - 1 && grid[i + 1][j] != '.')
                usable[grid[i + 1][j] - '1'] = false;
            // cout << i << " " << j << endl;
            if(0 < j && grid[i][j - 1] != '.')
                usable[grid[i][j - 1] - '1'] = false;
            // cout << i << " " << j << endl;
            rep(k, 5) {
                if(usable[k]) {
                    grid[i][j] = k + '1';
                    break;
                }
            }
        }
    }
    return grid;
}

#ifndef _debug
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) { cin >> grid[i]; }
    vector<string> res = solve(h, w, grid);
    rep(i, h) { cout << res[i] << endl; }
    return 0;
}
#endif