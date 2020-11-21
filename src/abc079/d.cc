#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int h, int w, vector<vector<int>> c, vector<vector<int>> a) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                c[j][k] = min(c[j][k], c[j][i] + c[i][k]);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(a[i][j] == -1) {
                continue;
            }
            res += c[a[i][j]][1];
        }
    }
    return res;
}
/*
int main() {
    int h, w;
    int INF = 1 << 29;
    vector<vector<int>> c(10, vector<int>(10, INF));
    cin >> h >> w;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }

    vector<vector<int>> a(h, vector<int>(w));

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve(h, w, c, a);
}
*/