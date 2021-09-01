#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int r, int c, int d, vector<vector<int>> &a) {
    int res = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(i + j <= d && (d - i - j) % 2 == 0)
                res = max(res, a[i][j]);
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int r, c, d;
    cin >> r >> c >> d;
    vector<vector<int>> a(r, vector<int>(c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> a[i][j];
    cout << solve(r, c, d, a) << endl;
    return 0;
}
#endif