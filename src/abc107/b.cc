#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<char>> trans(vector<vector<char>> a) {
    vector<vector<char>> at((int)a[0].size(), vector<char>((int)a.size()));
    for(int i = 0; i < (int)a.size(); i++) {
        for(int j = 0; j < (int)a[i].size(); j++) {
            at[j][i] = a[i][j];
        }
    }
    return at;
}

vector<vector<char>> drop(vector<vector<char>> a) {
    vector<vector<char>> res;
    for(int i = 0; i < (int)a.size(); i++) {
        bool ok = true;
        for(int j = 0; j < (int)a[i].size(); j++) {
            if(a[i][j] == '#')
                ok = false;
        }
        if(!ok) {
            vector<char> l(a[i]);
            res.push_back(l);
        }
    }
    return res;
}

vector<vector<char>> solve(int h, int w, vector<vector<char>> a) {
    vector<vector<char>> res = drop(a);
    res = trans(res);
    res = drop(res);
    res = trans(res);
    return res;
}

#ifndef _debug
int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++)  {
            cin >> a[i][j];
        }
    }
    vector<vector<char>> res = solve(h, w, a);
    for(int i = 0; i < (int)res.size(); i++) {
        for(int j = 0; j < (int)res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
#endif