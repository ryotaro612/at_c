#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(int w, int h, int n, vector<int> x, vector<int> y, vector<int> a) {
    vector<vector<bool>> area(h, vector<bool>(w, false));
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            for(int j = 0; j < x[i]; j++)
                for(int k = 0; k < h; k++)
                    area[k][j] = true;

        } else if(a[i] == 2) {
            for(int j = x[i]; j < w; j++)
                for(int k = 0; k < h; k++)
                    area[k][j] = true;

        } else if(a[i] == 3) {
            for(int j = 0; j < y[i]; j++)
                for(int k = 0; k < w; k++)
                    area[j][k] = true;

        } else if(a[i] == 4) {
            for(int j = y[i]; j < h; j++)
                for(int k = 0; k < w; k++)
                    area[j][k] = true;
        }
    }

    int res = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)
            if(!area[i][j])
                res++;
    }
    return res;
}

#ifndef _debug
int main() {
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n), y(n), a(n);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> a[i];
    cout << solve(w, h, n, x, y, a) << endl;
}
#endif