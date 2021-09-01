#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
vector<vector<int>> solve(int n, int m, vector<vector<int>> area) {
    vector<vector<int>> res(n, vector<int>(m, 0));
    for(int i = 0; i < n - 2; i++) {
        for(int j = 1; j < m - 1; j++) {
            if(area[i][j] > 0) {
                int dec = area[i][j];
                res[i + 1][j] += dec;
                area[i][j] -= dec;
                area[i + 1][j - 1] -= dec;
                area[i + 1][j + 1] -= dec;
                area[i + 2][j] -= dec;
            }
        }
    }
    return res;
}

#ifndef _debug
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> area(n, vector<int>(m));
    vector<string> temp(n);
    for(int i = 0; i < n; i++)
        cin >> temp[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            area[i][j] = temp[i][j] - '0';
    vector<vector<int>> res = solve(n, m, area);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }

    return 0;
}
#endif