#ifdef _debug
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<string> solve(int h, int w, vector<string> s) {
    vector<string> pre(s);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(s[i][j] == '#')
                continue;
            if(i != 0) {
                if(j != 0)
                    pre[i - 1][j - 1] = '.';
                pre[i - 1][j] = '.';
                if(j != w - 1)
                    pre[i - 1][j + 1] = '.';
            }
            if(j != 0)
                pre[i][j - 1] = '.';
            if(j != w - 1)
                pre[i][j + 1] = '.';
            if(i != h - 1) {
                if(j != 0)
                    pre[i + 1][j - 1] = '.';
                pre[i + 1][j] = '.';
                if(j != w - 1)
                    pre[i + 1][j + 1] = '.';
            }
        }
    }

    vector<string> check(pre);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(pre[i][j] == '#')
                continue;
            if((i != 0 && j != 0 && pre[i - 1][j - 1] == '#') ||
               (i != 0 && pre[i - 1][j] == '#') ||
               (i != 0 && j != w - 1 && pre[i - 1][j + 1] == '#') ||
               (j != 0 && pre[i][j - 1] == '#') ||
               (j != w - 1 && pre[i][j + 1] == '#') ||
               (i != h - 1 && j != 0 && pre[i + 1][j - 1] == '#') ||
               (i != h - 1 && pre[i + 1][j] == '#') ||
               (i != h - 1 && j != w - 1 && pre[i + 1][j + 1] == '#')) {
                check[i][j] = '#';
                continue;
            }
        }
    }
    /*
    for(auto pp : pre) {
        cout << pp << endl;
    }
    cout << "@@@@" << endl;
    for(auto pp : s) {
        cout << pp << endl;
    }
    cout << "!!!!" << endl;
    for(auto pp : check) {
        cout << pp << endl;
    }
    */
    if(check == s)
        return pre;

    return {};
}

#ifndef _debug
int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) {
        cin >> s[i];
    }
    vector<string> res = solve(h, w, s);
    if((int)res.size() > 0) {
        cout << "possible" << endl;
        for(int i = 0; i < h; i++)
            cout << res[i] << endl;
    } else
        cout << "impossible" << endl;
}
#endif
