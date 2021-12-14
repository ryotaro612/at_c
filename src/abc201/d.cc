#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> a;
int h, w;
vector<vector<pair<int, int>>> dp;

void dfs(int i, int j, bool t) {
    if(dp[i][j].first != -1 && dp[i][j].second != -1) {
        return;
    }
    if(i < h - 1) {
        dfs(i + 1, j, !t);
    }
    if(j < w - 1) {
        dfs(i, j + 1, !t);
    }

    if(i == h - 1) {
        int change = (a[i][j + 1] == '+' ? 1 : -1);
        if(t) {
            dp[i][j] =
                make_pair(dp[i][j + 1].first + change, dp[i][j + 1].second);
        } else {
            dp[i][j] =
                make_pair(dp[i][j + 1].first, dp[i][j + 1].second + change);
        }
        return;
    }
    if(j == w - 1) {
        int change = (a[i + 1][j] == '+' ? 1 : -1);
        if(t) {
            dp[i][j] =
                make_pair(dp[i + 1][j].first + change, dp[i + 1][j].second);
        } else {
            dp[i][j] =
                make_pair(dp[i + 1][j].first, dp[i + 1][j].second + change);
        }
        return;
    }
    int down = (a[i + 1][j] == '+' ? 1 : -1),
        right = (a[i][j + 1] == '+' ? 1 : -1);
    if(t) {
        if(dp[i + 1][j].first + down - dp[i + 1][j].second >=
           dp[i][j + 1].first + right - dp[i][j + 1].second) {
            dp[i][j] =
                make_pair(dp[i + 1][j].first + down, dp[i + 1][j].second);
        } else {
            dp[i][j] =
                make_pair(dp[i][j + 1].first + right, dp[i][j + 1].second);
        }
    } else {
        if((dp[i + 1][j].second + down) - dp[i + 1][j].first >=
           (dp[i][j + 1].second + right) - dp[i][j + 1].first) {
            dp[i][j] =
                make_pair(dp[i + 1][j].first, dp[i + 1][j].second + down);
        } else {
            dp[i][j] =
                make_pair(dp[i][j + 1].first, dp[i][j + 1].second + right);
        }
    }
}

#ifdef ONLINE_JUDGE
int main() {
    cin >> h >> w;
    a.resize(h);
    for(int i = 0; i < h; i++) {
        cin >> a[i];
    }
    dp.resize(h);
    for(int i = 0; i < h; i++) {
        dp[i] = vector<pair<int, int>>(w, make_pair(-1, -1));
    }
    dp[h - 1][w - 1] = make_pair(0, 0);
    dfs(0, 0, true);
    /*
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << "(" << dp[i][j].first << "," << dp[i][j].second << ") ";
        }
        cout << endl;
    }
    */

    if(dp[0][0].first > dp[0][0].second) {
        cout << "Takahashi" << endl;
    } else if(dp[0][0].first == dp[0][0].second) {
        cout << "Draw" << endl;
    } else {
        cout << "Aoki" << endl;
    }
    return 0;
}
#endif