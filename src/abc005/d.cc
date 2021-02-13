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
    vector<vector<int>> areas = calc_area(n, d);
    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }
    */
    /*
     cout << query_area(0, 0, 1, 1, areas) << endl;
     cout << query_area(0, 0, 3, 3, areas) << endl;
     cout << query_area(0, 0, 1, 3, areas) << endl;
     cout << query_area(0, 0, 3, 1, areas) << endl;
     cout << query_area(0, 0, 2, 2, areas) << endl;
     cout << query_area(1, 1, 1, 2, areas) << endl;
     */
    vector<int> cache(n + 1, 0);
    for(int use = 1; use <= n; use++) {
        vector<pair<int, int>> rect_patterns = list_rect_patterns(use);
        /*
        for(auto x: rect_patterns) {
            cout << x.first << " " << x.second << endl;
        }
        cout << "  === " << endl;
        */
        int temp = 0;
        for(auto pattern : rect_patterns) {
            int width = pattern.first, height = pattern.second;
            for(int x = 0; x + width - 1 < n; x++) {
                for(int y = 0; y + height - 1 < n; y++) {
                    temp = max(query_area(x, y, width, height, areas), temp);
                }
            }
        }
        cache[use] = max(temp, cache[use - 1]);
    }
    vector<int> res(q);
    for(int i=0;i<q;i++) {
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