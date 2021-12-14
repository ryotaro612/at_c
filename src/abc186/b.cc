#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int h, int w, vector<vector<int>> a) {
    int mini = 101;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            mini = min(mini, a[i][j]);
        }
    }
    int res = 0;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            res += a[i][j] - mini;
    return res;
}

#ifdef ONLINE_JUDGE
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    cout << solve(h, w, a) << endl;
    return 0;
}
#endif