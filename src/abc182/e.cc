#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int h, int w, int n, int m, vector<int> a, vector<int> b,
          vector<int> c, vector<int> d) {
    int block = -1, light = 1;
    vector<vector<int>> ve(h, vector<int>(w, 0)), ho(h, vector<int>(w, 0));
    for(int i = 0; i < n; i++)
        ve[a[i] - 1][b[i] - 1] = ho[a[i] - 1][b[i] - 1] = light;
    for(int i = 0; i < m; i++)
        ve[c[i] - 1][d[i] - 1] = ho[c[i] - 1][d[i] - 1] = block;

    for(int i = 0; i < n; i++) {
        for(int j = a[i] - 2; j >= 0; j--) {
            if(ve[j][b[i] - 1] != 0)
                break;
            ve[j][b[i] - 1] = light;
        }
        for(int j = a[i]; j < h; j++) {
            if(ve[j][b[i] - 1] != 0)
                break;
            ve[j][b[i] - 1] = light;
        }

        for(int j = b[i] - 2; j >= 0; j--) {
            if(ho[a[i] - 1][j] != 0)
                break;
            ho[a[i] - 1][j] = light;
        }
        for(int j = b[i]; j < w; j++) {
            if(ho[a[i] - 1][j] != 0)
                break;
            ho[a[i] - 1][j] = light;
        }
    }
    int res = 0;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if(ve[i][j] > 0 || ho[i][j] > 0)
                res++;
    return res;
}

#ifndef _debug
int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for(int i = 0; i < m; i++)
        cin >> c[i] >> d[i];

    cout << solve(h, w, n, m, a, b, c, d) << endl;
}
#endif