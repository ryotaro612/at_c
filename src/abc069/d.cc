#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(int h, int w, int n, vector<int> a) {

    vector<int> items;
    for(int i = 0; i < (int)a.size(); i++) {
        for(int j = 0; j < a[i]; j++) {
            items.push_back(i + 1);
        }
    }
    vector<vector<int>> res(h, vector<int>(w));
    bool right = true;
    int hh = 0, ww = 0;
    int i = 0;
    while(i < h * w) {
        res[hh][ww] = items[i++];
        if(right) {
            if(ww < w-1) {
                ww++;
            } else {
                hh++;
                right = false;
            }
        } else {
            if(ww > 0) {
                ww--;
            } else {
                hh++;
                right = true;
            }
        }
    }
    return res;
}
/*
int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> res = solve(h, w, n, a);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << res[i][j];
            if(j != w - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
*/