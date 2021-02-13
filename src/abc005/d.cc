#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> calc_area(int n, vector<vector<int>> d) {
    vector<vector<int>> area(n, vector<int>(n));
    area[0][0] = d[0][0];
    for(int i = 1; i < n; i++) {
        area[0][i] += area[0][i - 1] + d[0][i];
        area[i][0] += area[i - 1][0] + d[i][0];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            area[i][j] = (area[i - 1][j] + area[i][j - 1] + d[i][j] -
                          area[i - 1][j - 1]);
        }
    }
    return area;
}

vector<int> solve(int n, vector<vector<int>> d, int q, vector<int> p) {
    vector<int> res(q);
    vector<vector<int>> area = calc_area(n, d);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }
    return res;
}
/*
int main() {
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    int q;
    cin >> q;
    vector<int> p(q);
    for(int i = 0; i < q; i++) {
        cin >> p[i];
    }
    vector<int> res = solve(n, d, q, p);
    for(int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }
    return 0;
}
*/