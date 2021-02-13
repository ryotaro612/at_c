#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> calc_area(int n, vector<vector<int>> d) {
    vector<vector<int>> area(n, vector<int>(n, 0));
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

vector<pair<int, int>> list_rect_patterns(int area) {
    vector<pair<int, int>> patterns;
    for(int w = 1; w <= area; w++) {
        if(area % w == 0) {
            patterns.push_back(make_pair(w, area / w));
        }
    }
    return patterns;
}
int query_area(int x, int y, int width, int height,
               vector<vector<int>> &areas) {

    int res = areas[y + height - 1][x + width - 1];
    if(y != 0) {
        res -= areas[y - 1][x + width - 1];
    }
    if(x != 0) {
        res -= areas[y + height - 1][x - 1];
    }
    if(y != 0 && x != 0) {
        res += areas[y - 1][x - 1];
    }
    return res;
}

vector<int> solve(int n, vector<vector<int>> d, int q, vector<int> p) {
    vector<vector<int>> areas(n, vector<int>(n, 0));
    areas[0][0] = d[0][0];
    for(int i = 1; i < n; i++) {
        areas[0][i] += areas[0][i - 1] + d[0][i];
        areas[i][0] += areas[i - 1][0] + d[i][0];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            areas[i][j] = (areas[i - 1][j] + areas[i][j - 1] + d[i][j] -
                           areas[i - 1][j - 1]);
        }
    }
    vector<int> cache(n * n + 1, 0);
    for(int use = 1; use <= n * n; use++) {
        vector<pair<int, int>> rect_patterns = list_rect_patterns(use);
        int temp = 0;
        for(auto pattern : rect_patterns) {
            int width = pattern.first, height = pattern.second;
            for(int x = 0; x + width - 1 < n; x++) {
                for(int y = 0; y + height - 1 < n; y++) {

                    int rect = areas[y + height - 1][x + width - 1];
                    if(y != 0) {
                        rect -= areas[y - 1][x + width - 1];
                    }
                    if(x != 0) {
                        rect -= areas[y + height - 1][x - 1];
                    }
                    if(y != 0 && x != 0) {
                        rect += areas[y - 1][x - 1];
                    }
                    temp = max(rect, temp);
                }
            }
        }
        cache[use] = max(temp, cache[use - 1]);
    }
    vector<int> res(q, 0);
    for(int i = 0; i < q; i++) {
        res[i] = cache[p[i]];
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