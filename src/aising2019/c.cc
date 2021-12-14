#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll solve(int h, int w, vector<string> &s) {
    vector<vector<bool>> used(h, vector<bool>(w, false));
    ll res = 0ll;
    rep(i, h) {
        rep(j, w) {
            if(used[i][j])
                continue;
            queue<pair<int, int>> que;
            que.push({i, j});
            ll black = 0, white = 0;
            used[i][j] = true;
            while(!que.empty()) {
                int x = que.front().second;
                int y = que.front().first;
                if(s[y][x] == '#')
                    black++;
                else
                    white++;
                que.pop();
                if(y > 0 && s[y][x] != s[y - 1][x] && !used[y - 1][x]) {
                    que.push({y - 1, x});
                    used[y - 1][x] = true;
                }
                if(x < w - 1 && s[y][x] != s[y][x + 1] && !used[y][x + 1]) {
                    que.push({y, x + 1});
                    used[y][x + 1] = true;
                }
                if(y < h - 1 && s[y][x] != s[y + 1][x] && !used[y + 1][x]) {
                    que.push({y + 1, x});
                    used[y + 1][x] = true;
                }
                if(0 < x && s[y][x] != s[y][x - 1] && !used[y][x - 1]) {
                    que.push({y, x - 1});
                    used[y][x - 1] = true;
                }
            }
            res += black * white;
        }
    }
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    cout << solve(h, w, s) << endl;
    return 0;
}
#endif