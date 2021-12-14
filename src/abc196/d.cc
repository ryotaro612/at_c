#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dfs(vector<vector<bool>> &t, int h, int w, int a, int b, int index) {
    if(index == h * w) {
        if(a == 0 && b == 0) {
            bool ok = true;
            for(int y = 0; y < h; y++) {
                for(int x = 0; x < w; x++) {
                    if(!t[y][x]) {
                        ok = false;
                    }
                }
                if(ok)
                    return 1;
            }
            return 0;
        }
    }
    int y = index / w, x = index % w;
    if(t[y][x])
        return dfs(t, h, w, a, b, index + 1);
    int res = 0;
    bool ok = false;
    if(b > 0) {
        ok = true;
        t[y][x] = true;
        res += dfs(t, h, w, a, b - 1, index + 1);
        t[y][x] = false;
    }
    if(a > 0) {
        if(x < w - 1 && !t[y][x + 1]) {
            ok = true;
            t[y][x] = t[y][x + 1] = true;
            res += dfs(t, h, w, a - 1, b, index + 1);
            t[y][x] = t[y][x + 1] = false;
        }
        if(y < h - 1 && !t[y + 1][x]) {
            ok = true;
            t[y][x] = t[y + 1][x] = true;
            res += dfs(t, h, w, a - 1, b, index + 1);
            t[y][x] = t[y + 1][x] = false;
        }
    }
    return ok ? res : 0;
}

int solve(int h, int w, int a, int b) {
    vector<vector<bool>> t(h, vector<bool>(w, false));
    return dfs(t, h, w, a, b, 0);
}

#ifdef ONLINE_JUDGE
int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    cout << solve(h, w, a, b) << endl;
    return 0;
}
#endif